#include "Vector.hpp"
#include "VectorIterator.hpp"
#include <cstdlib> 
#include <iostream>
constexpr std::size_t INITIAL_CAPACITY = 20;

template <typename TValue>
Vector<TValue>::Vector(){
    m_capacity = INITIAL_CAPACITY;
    m_data = new TValue[INITIAL_CAPACITY];
    m_size = 0;
}

template <typename TValue>
Vector<TValue>::Vector(const Vector& rhs){
    delete[] m_data;
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity; 
    m_data = new TValue[m_capacity]; 

    std::copy(m_data, rhs.m_data, m_capacity*sizeof(TValue));
}

template <typename TValue>
Vector<TValue>::Vector(const Vector&& rhs){
    m_data = rhs.m_data;
    rhs.m_data = nullptr;
}

template <typename TValue>
Vector<TValue>& Vector<TValue>::operator=(Vector&& rhs){
    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    m_data = rhs.m_data;

    rhs.m_data = nullptr;
    rhs.m_capacity = rhs.m_size = 0;
    
    return *this;
}

template <typename TValue>
Vector<TValue>::~Vector(){
    delete[] m_data;
    m_data = NULL;
}

template <typename TValue>
Vector<TValue>& Vector<TValue>::operator=(const Vector& rhs){
    if (m_capacity != rhs.m_capacity){
        delete[] m_data;
        m_data = new TValue[rhs.m_capacity];
    }

    m_capacity = rhs.m_capacity;
    std::copy(m_data, rhs.m_data, m_capacity*sizeof(TValue));

    return *this;
} 

template <typename TValue>
std::size_t Vector<TValue>::getSize(){
    return this->m_size;
}

template <typename TValue>
std::size_t Vector<TValue>::getCapacity(){
    return this->m_capacity;
}

template <typename TValue>
void Vector<TValue>::insert(TIterator pos, TValue element){
   if(m_size==m_capacity){
        reserve((1+m_capacity)*2);
    }

    for (TIterator current = ipos+1; current != end(); ++current){
        *current = *(current-1);
    }
      
    this->m_size++;
    this->m_data[ipos]=element;
}  

template <typename TValue>
void Vector<TValue>::pushFront(TValue element){
    insert(0, element);
}

template <typename TValue>
void Vector<TValue>::pushBack(TValue element){
    this->m_data[m_size] = element;
}

template <typename TValue>
void Vector<TValue>::erase(TIterator pos){
    TIterator end = end();

    for (TIterator current = pos; current != end; ++current){
        TIterator next = current;
        ++next;
        current = next;        
    }
}

template <typename TValue>
void Vector<TValue>::popFront(){
    erase(0);
}

template <typename TValue>
void Vector<TValue>::popBack(){
    erase(m_size-1);
} 

template <typename TValue>
const TValue& Vector<TValue>::operator[](std::size_t idx) const{
    return this->m_data[idx];
}

template <typename TValue>
TValue& Vector<TValue>::getFront(){
    return this->m_data[0];
}

template <typename TValue>
TValue& Vector<TValue>::getBack(){
    return this->m_data[this->m_size-1];
}

template <typename TValue>
TValue& Vector<TValue>::operator[](std::size_t idx){
    this->m_data[idx];
}

template <typename TValue>
void Vector<TValue>::setFront(TValue element){
    this->m_data[0] = element;
}

template <typename TValue>
void Vector<TValue>::setBack(TValue element){
    this->m_data[m_size-1] = element;
}

template <typename TValue>
void Vector<TValue>::clear(){
  this->m_size = 0;
}

template <typename TValue>
bool Vector<TValue>::isEmpty(){
   return m_size == 0;
}

template <typename TValue>
std::ostream& operator<<(std::ostream& os, const Vector<TValue>& task){
    for(std::size_t idx = 0; idx < task.m_size; ++idx){
       os << task.m_data[idx] << " ";
    }
    os << std::endl;
    return os;
}

template <typename TValue>
void Vector<TValue>::reserve(std::size_t newCapacity){
    if(this->m_capacity < newCapacity){
        TValue* new_data = new TValue[newCapacity]; 
        this->m_capacity = newCapacity;

        for(size_t i = 0; i < this->m_size; ++i){
            new_data[i] = this->m_data[i];
        }

        delete[] this->m_data; 
        this->m_data = new_data;
    }
}

template <typename TValue>
void Vector<TValue>::resize(std::size_t newSize){
    if(newSize < 0) return;
    if(newSize < m_capacity){
        for(std::size_t idx = m_size; idx < newSize; ++idx){
            m_data[idx] = TValue();
        }
    }else{
        reserve((m_capacity + 1) * 2);
    }
    m_size = newSize;
}

template <typename TValue>
TIterator Vector<TValue>::begin(){
    return VectorIterator<TValue>(m_data);
}

template <typename TValue>
TIterator Vector<TValue>::end(){
    return VectorIterator<TValue>(m_data + m_size);
}