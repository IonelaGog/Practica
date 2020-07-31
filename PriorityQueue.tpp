#include "PriorityQueue.hpp"
#include <cstdlib> 
#include <iostream>

template <typename TValue, template <typename> typename TContainer>
PriorityQueue<TValue, TContainer>::PriorityQueue(){
    m_container = 0;
}

template <typename TValue, template <typename> typename TContainer>
PriorityQueue<TValue, TContainer>::PriorityQueue(const PriorityQueue& rhs){
    m_container = rhs.m_container;
}

template <typename TValue, template <typename> typename TContainer>
PriorityQueue<TValue, TContainer>::~PriorityQueue(){
    delete[] m_container;
    m_container = NULL;
}

template <typename TValue, template <typename> typename TContainer>
PriorityQueue<TValue, TContainer>& PriorityQueue<TValue, TContainer>::operator=(const PriorityQueue& rhs){
    m_container = rhs.m_container;
}

template <typename TValue, template <typename> typename TContainer>
std::size_t PriorityQueue<TValue, TContainer>::getSize(){
    return m_container.getSize();
}

template <typename TValue, template <typename> typename TContainer>
void PriorityQueue<TValue, TContainer>::push(TValue element){
    TValue 
    m_container.pushBack(element);
}

template <typename TValue, template <typename> typename TContainer>
TValue PriorityQueue<TValue, TContainer>::pop(){
    TValue element = m_container.getFront();
    m_container.popFront(element);
    return element;
}

template <typename TValue, template <typename> typename TContainer>
void PriorityQueue<TValue, TContainer>::clear(){
    std::size_t m_size;

    m_container.clear();
    m_size = 0;
}

template <typename TValue, template <typename> typename TContainer>
bool PriorityQueue<TValue, TContainer>::isEmpty(){
    return m_container.empty();
}

template <typename U, template <typename> typename UTContainer>
std::ostream& operator<<(std::ostream& os, const PriorityQueue<U, UTContainer>& q){
    os << q.m_container;
    return os;
}