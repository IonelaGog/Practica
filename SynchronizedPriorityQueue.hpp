#ifndef SYNCHRONIZEDPRIORITYQUEUE_HPP
#define SYNCHRONIZEDPRIORITYQUEUE_HPP

#include <cstddef>
#include <cstdlib>
#include <mutex>
#include "Vector.hpp"
#include "PriorityQueue.hpp"
#include <thread>


template <typename TValue, typename TContainer, typename TLock = std::mutex>
class SynchronizedPriorityQueue{
    public:
        SynchPriorityQueue();
        SynchPriorityQueue(const SynchronizedPriorityQueue& rhs);
        ~SynchPriorityQueue();

        SynchronizedPriorityQueue& operator=(const SynchronizedPriorityQueue& rhs);

        std::size_t getSize();

        void push(TValue element);
        TValue pop();
        bool tryPop(TValue element);

        void clear();
        bool isEmpty();

        template <typename UValue, typename Ucontainer, typename ULock>
        friend std::ostream& operator<<(std::ostream& os, const SynchronizedPriorityQueue<UValue, UContainer, ULock>& task);

        typename TContainer<TValue>::TIterator begin();
        typename TContainer<TValue>::TIterator end();

    private:
        TContainer<TValue> m_container;
        TLock m_lock;       
};

#include "SynchronizedPriorityQueue.tpp"

#endif //SYNCHRONIZEDPRIORITYQUEUE_HPP