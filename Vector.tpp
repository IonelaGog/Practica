#include "Vector.hpp"
#include <cstdlib> 
#include <iostream>

template <typename TValue>
Vector<TValue>::Vector(){
    for (std::size_t idx = 0; idx < Vector::getCapacity(); ++idx){
        this->m_data[idx] = rand();
    }
}

template <typename TValue>
Vector<TValue>::Vector(const Vector& rhs){
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity; 
    m_data = new T[m_capacity]; 
    memcpy(m_data, rhs.m_data, m_capacity * sizeof(T));
}

template <typename TValue>
Vector<TValue>::~Vector(){
    for (std::size_t idx = 0; idx < Vector::getCapacity(); ++idx){
        this->m_data[idx] = 0;    
    }
}

/*
int Vector::getElement(std::size_t idx){
     if ((idx < 0) || (idx > m_size)){
        std::cout << "Position isn't valid" << std::endl;
        return 1;
     }
    else
        return this->m_data[idx];
}

void Vector::setElement(std::size_t idx, int element){
    if ((idx < 0) || (idx > m_size))
        std::cout << "Position isn't valid" << std::endl;
    else
        this->m_data[idx] = element;
}*/

template <typename TValue>
std::size_t Vector<TValue>::getSize(){
    return this->m_size;
}

template <typename TValue>
std::size_t Vector<TValue>::getCapacity(){
    return this->m_capacity;
}

template <typename TValue>
void Vector<TValue>::insert(std::size_t idx, TValue element){
    if ((idx < 0) || (idx > m_size))
        std::cout << "Position isn't valid" << std::endl;
    else{
        m_size = m_size + 1;

        for (std::size_t id = idx; id < this->getSize()-2; ++id){
        this->m_data[id + 1] = this->m_data[id];
        }
     this->m_data[idx] = element;
    }  
}

template <typename TValue>
void Vector<TValue>::pushFront(TValue element){
    m_size = m_size + 1;

    for (std::size_t idx = 0; idx < this->getSize()-2; ++idx){
        this->m_data[idx + 1] = this->m_data[idx];
    }

    this->m_data[0] = element;
}

template <typename TValue>
void Vector<TValue>::pushBack(TValue element){
    m_size = m_size + 1;
    this->m_data[m_size] = element;
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
void Vector<TValue>::setFront(TValue element){
    this->m_data[0] = element;
}

template <typename TValue>
void Vector<TValue>::setBack(TValue element){
    this->m_data[m_size] = element;
}

template <typename TValue>
void Vector<TValue>::clear(){
    for (std::size_t idx = 0; idx < m_size-1; ++idx){
        this->m_data[idx] = 0;
    }
}

template <typename TValue>
bool Vector<TValue>::empty(){
   /* bool flag = true;
    int idx = 0;

    while ((idx < m_size - 1) || (flag == true)){
        if (this->m_data[idx] == 0)
            idx = idx + 1;
        else
            flag = false;
    }

    return flag;*/

    if (this->m_size != 0)
        return false;
    else
        return true;
}