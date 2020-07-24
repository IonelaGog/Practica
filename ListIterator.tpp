#include "ListIterator.hpp"

template <typename TValue>
ListIterator<TValue>::ListIterator(TValue* value){
    m_value = value;
}

template <typename TValue>
ListIterator<TValue>::ListIterator(const ListIterator& rhs){
    m_value = rhs.m_value;
}

template <typename TValue>
ListIterator<TValue>& ListIterator<TValue>::operator=(const ListIterator& rhs){
    m_value = rhs.m_value;
    return *this;
}

template <typename TValue>
bool ListIterator<TValue>::operator!=(const ListIterator& rhs){
    return m_value != rhs.m_value;
}

template <typename TValue>
bool ListIterator<TValue>::operator<(const ListIterator& rhs){
    return m_value < rhs.m_value;
}

template <typename TValue>
ListIterator<TValue>& ListIterator<TValue>::operator++(){
    ++m_value;
    return *this;
}

template <typename TValue>
ListIterator<TValue>& ListIterator<TValue>::operator--(){
    --m_value;
    return *this;
}

template <typename TValue>
ListIterator<TValue>& ListIterator<TValue>::operator+=(std::size_t difference){
    m_value += difference;
    return *this;
}

template <typename TValue>
ListIterator<TValue>& ListIterator<TValue>::operator-=(std::size_t difference){
    m_value -= difference;
    return *this;
}

template <typename TValue>
TValue ListIterator<TValue>::operator*(){
    return *m_value;
}