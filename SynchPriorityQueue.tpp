#include "SynchPriorityQueue.hpp"
#include <mutex>

template <typename TValue, typename TContainer, typename TLock>
SynchPriorityQueue<TValue, TContainer, TLock>::SynchPriorityQueue()
{
}

template <typename TValue, typename TContainer, typename TLock>
SynchPriorityQueue<TValue, TContainer, TLock>::SynchPriorityQueue(const SynchPriorityQueue &rhs)
{
    m_lock.lock();
    m_container = rhs.m_container;
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
SynchPriorityQueue<TValue, TContainer, TLock>::~SynchPriorityQueue()
{
}

template <typename TValue, typename TContainer, typename TLock>
SynchPriorityQueue<TValue, TContainer, TLock> &SynchPriorityQueue<TValue, TContainer, TLock>::operator=(const SynchPriorityQueue &rhs)
{
    m_lock.lock();
    m_container = rhs.m_container;
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
std::size_t SynchPriorityQueue<TValue, TContainer, TLock>::getSize()
{
    m_lock.lock();
    return m_container.getSize();
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
void SynchPriorityQueue<TValue, TContainer, TLock>::push(const TValue &element)
{
    std::size_t poz = 0;

    m_lock.lock();
    for (std::size_t idx = 0; idx < m_container.getSize(); ++idx)
    {
        if (m_container[idx] < element)
        {
            ++poz;
        }
    }
    m_container.insert(poz, element);
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
void SynchPriorityQueue<TValue, TContainer, TLock>::push(TValue &&element)
{
    std::size_t poz = 0;

    m_lock.lock();
    for (std::size_t idx = 0; idx < m_container.getSize(); ++idx)
    {
        if (m_container[idx] < element)
        {
            ++poz;
        }
    }
    m_container.insert(m_container.begin() + poz, std::move(element));
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
TValue SynchPriorityQueue<TValue, TContainer, TLock>::pop()
{
    m_lock.lock();
    TValue val = m_container.getBack();
    m_container.popBack();
    m_lock.unlock();

    return val;
}

template <typename TValue, typename TContainer, typename TLock>
bool SynchPriorityQueue<TValue, TContainer, TLock>::tryPop(TValue &element)
{
    std::lock_guard<std::mutex> lock(m_lock);

    if (!m_container.isEmpty())
    {
        element = std::move(m_container.getBack());
        m_container.popBack();
        return true;
    }

    return false;
}

template <typename TValue, typename TContainer, typename TLock>
void SynchPriorityQueue<TValue, TContainer, TLock>::clear()
{
    m_lock.lock();
    m_container = 0;
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
bool SynchPriorityQueue<TValue, TContainer, TLock>::isEmpty()
{
    m_lock.lock();
    return m_container.isEmpty();
    m_lock.unlock();
}

template <typename UValue, typename UContainer, typename ULock>
std::ostream &operator<<(std::ostream &os, const SynchPriorityQueue<UValue, UContainer, ULock> &task)
{
    os << task.m_container;
    return os;
}

template <typename TValue, typename TContainer, typename TLock>
auto SynchPriorityQueue<TValue, TContainer, TLock>::begin()
{
    m_lock.lock();
    return m_container.begin();
    ;
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
auto SynchPriorityQueue<TValue, TContainer, TLock>::end()
{
    m_lock.lock();
    return m_container.end();
    m_lock.unlock();
}