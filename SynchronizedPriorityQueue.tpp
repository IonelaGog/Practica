#include "SynchronizedPriorityQueue.hpp"

using TIterator = typename TContainer::TIterator;

template <typename TValue, typename TContainer, typename TLock>
SynchronizedPriorityQueue<TValue, TContainer, TLock>::SynchPriorityQueue(){

}

template <typename TValue, typename TContainer, typename TLock>
SynchronizedPriorityQueue<TValue, TContainer, TLock>::SynchPriorityQueue(const SynchronizedPriorityQueue& rhs){
    m_lock.lock();
    m_container = rhs.m_container;
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
SynchronizedPriorityQueue<TValue, TContainer, TLock>::~SynchPriorityQueue(){
    
}

template <typename TValue, typename TContainer, typename TLock>
SynchronizedPriorityQueue<TValue, TContainer, TLock>& SynchronizedPriorityQueue<TValue, TContainer, TLock>::operator=(const SynchronizedPriorityQueue& rhs){
    m_lock.lock();
    m_container = rhs.m_container;
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
std::size_t SynchronizedPriorityQueue<TValue, TContainer, TLock>::getSize(){
    m_lock.lock();
    return m_container.getSize();
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
void SynchronizedPriorityQueue<TValue, TContainer, TLock>::push(TValue element){
    std::size_t poz = 0;
   
    m_lock.lock();
        for (std::size_t idx = 0; idx < m_container.size(); ++idx){
            if (m_container[idx] < element){
                ++poz;
            }
        }
    m_container.insert(poz,element);
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
TValue SynchronizedPriorityQueue<TValue, TContainer, TLock>::pop(){
    m_lock.lock();
    TValue val = m_container.getBack();
    m_container.popBack();
    m_lock.unlock();

    return val;
}

template <typename TValue, typename TContainer, typename TLock>
bool SynchronizedPriorityQueue<TValue, TContainer, TLock>::tryPop(TValue element){
    if(!m_container.isEmpty()){
        value = m_container.pop();
        return true;
    }
    return false;
}

template <typename TValue, typename TContainer, typename TLock>
void SynchronizedPriorityQueue<TValue, TContainer, TLock>::clear(){
    m_lock.lock();
    m_container = 0;
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
bool SynchronizedPriorityQueue<TValue, TContainer, TLock>::isEmpty(){
    m_lock.lock();
    return m_container.isEmpty();
    m_lock.unlock();
}

template <typename UValue, typename UContainer, typename ULock>
std::ostream& operator<<(std::ostream& os, const SynchronizedPriorityQueue<UValue, UContainer, ULock>& task)
{
    os << task.m_container;
    return os;
}

template <typename TValue, typename TContainer, typename TLock>
TIterator SynchronizedPriorityQueue<TValue, TContainer, TLock>::begin(){
    m_lock.lock();
    return TIterator<TValue>(m_container);
    m_lock.unlock();
}

template <typename TValue, typename TContainer, typename TLock>
TIterator SynchronizedPriorityQueue<TValue, TContainer, TLock>::end(){
    m_lock.lock();
    return TIterator<TValue>(m_size+m_container);
    m_lock.unlock();
}