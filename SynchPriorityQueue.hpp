#ifndef SYNCHPRIORITYQUEUE_HPP
#define SYNCHPRIORITYQUEUE_HPP

#include <cstddef>
#include <cstdlib>
#include <mutex>
#include "Vector.hpp"
#include "PriorityQueue.hpp"
#include <thread>


template <typename TValue, typename TContainer = Vector<TValue>, typename TLock = std::mutex>
class SynchPriorityQueue{
    public:
        using TIterator = typename TContainer<TValue>::TIterator;

        SynchPriorityQueue();
        SynchPriorityQueue(const SynchPriorityQueue& rhs);
        ~SynchPriorityQueue();

        SynchPriorityQueue& operator=(const SynchPriorityQueue& rhs);

        std::size_t getSize();

        void push(TValue element);
        TValue pop();
        bool tryPop(TValue element);

        void clear();
        bool isEmpty();

        template <typename UValue, typename UContainer, typename ULock>
        friend std::ostream& operator<<(std::ostream& os, const SynchPriorityQueue<UValue, UContainer, ULock>& task);

        TIterator begin();
        TIterator end();

    private:
        TContainer<TValue> m_container;
        TLock m_lock;       
};

#include "SynchPriorityQueue.tpp"

#endif //SYNCHRONIZEDPRIORITYQUEUE_HPP