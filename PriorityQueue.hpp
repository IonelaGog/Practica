#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <cstddef>

template <typename TValue, template <typename> typename TContainer>
class PriorityQueue
{
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue &rhs);
    ~PriorityQueue();

    PriorityQueue &operator=(const PriorityQueue &rhs);

    std::size_t getSize();

    void push(TValue element);
    TValue pop();

    void clear();
    bool isEmpty();

    template <typename U, template <typename> typename UTContainer>
    friend std::ostream &operator<<(std::ostream &os, const PriorityQueue<U, UTContainer> &task);

    using TIterator = typename TContainer<TValue>::TIterator;

    TIterator begin();
    TIterator end();

private:
    TContainer<TValue> m_container;
};

#include "PriorityQueue.tpp"

#endif //PRIORITYQUEUE_HPP