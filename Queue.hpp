#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

template <typename TValue, template <typename> typename TContainer>
class Queue{
    public:
        Queue();
        Queue(const Queue& rhs);
        ~Queue();

        Queue& operator=(const Queue& rhs);

        std::size_t getSize();

        void push(TValue element);
        TValue pop();

        void clear();
        bool isEmpty();

        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, const Queue<TValue,TContainer>& task);

        using TIterator = typename TContainer<TValue>::TIterator;

        TIterator begin();
        TIterator end();

    private:
        TContainer m_container;    
};

#include "Queue.tpp"

#endif//QUEUE_HPP