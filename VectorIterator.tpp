#include "VectorIterator.hpp"
#include <cstdlib> 
#include <iostream>

template <typename TValue>
VectorIterator<TValue>::VectorIterator(TValue* value):m_value(value){}

template <typename TValue>
VectorIterator<TValue>::VectorIterator(const VectorIterator& rhs):m_value(rhs.m_value){}

template <typename TValue>
VectorIterator<TValue>& VectorIterator<TValue>::operator=(const VectorIterator& rhs){
    return m_value == rhs.m_value;
} 

template <typename TValue>
bool VectorIterator<TValue>::operator!=(const VectorIterator& rhs){
    return m_value != rhs.m_value;
}

template <typename TValue>
bool VectorIterator<TValue>::operator<(const VectorIterator& rhs){
    return m_value < rhs.m_value;
}

template <typename TValue>
VectorIterator<TValue>& VectorIterator<TValue>::operator++(){
    ++m_value;
    return *this;
}

template <typename TValue>
VectorIterator<TValue>& VectorIterator<TValue>::operator--(){
    --m_value;
    return *this;
} 

template <typename TValue>
VectorIterator<TValue>& VectorIterator<TValue>::operator+=(std::size_t difference){
    m_value += difference;
    return *this;
}

template <typename TValue>
VectorIterator<TValue>& VectorIterator<TValue>::operator-=(std::size_t difference){
    m_value -= difference;
    return *this;
}

template <typename TValue>
TValue VectorIterator<TValue>::operator*(){
    return *m_value;
}

template <typename TValue>
VectorIterator<TValue>& VectorIterator<TValue>::operator+(std::size_t difference){
    TIterator it;
    it.m_value = m_value+difference;

    return it;
}

template <typename TValue>
VectorIterator<TValue>& VectorIterator<TValue>::operator-(std::size_t difference){
    TIterator it;
    it.m_value = m_value-difference;

    return it;
}
