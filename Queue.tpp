#include "Queue.hpp"
#include <cstdlib> 
#include <iostream>

template <typename TValue, template <typename> typename TContainer>
Queue<TValue, TContainer>::Queue(){
    m_container = NULL;
}

template <typename TValue, template <typename> typename TContainer>
Queue<TValue, TContainer>::Queue(const Queue& rhs)
{
    m_container = rhs.m_container;
}

template <typename TValue, template <typename> typename TContainer>
Queue<TValue, TContainer>::~Queue(){
    delete [] m_container;
}

template <typename TValue, template <typename> typename TContainer>
Queue<TValue, TContainer>& Queue<TValue, TContainer>::operator=(const Queue& rhs){
    m_container = rhs.m_container;
}

template <typename TValue, template <typename> typename TContainer>
size_t Queue<TValue, TContainer>::getSize(){
    return m_container.getSize();
}

template <typename TValue, template <typename> typename TContainer>
void Queue<TValue, TContainer>::push(TValue element){
    m_container.pushBack(element);
}

template <typename T, template <typename> typename TContainer>
T Queue<T,TContainer>::pop(){
    T val = m_container.getFront();
    m_container.popFront();
    return val;
}

template <typename T, template <typename> typename TContainer>
void Queue<T,TContainer>::clear(){
    m_container.clear();
    m_size = 0;
}

template <typename TValue, template <typename> typename TContainer>
bool Queue<TValue, TContainer>::isEmpty(){
    return m_container.empty();
}

template <typename U, template <typename> typename UTContainer>
std::ostream& operator<<(std::ostream& os, const Queue<U, UTContainer>& q){
    os << q.m_container;
    return os;
}