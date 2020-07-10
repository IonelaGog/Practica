#include "Vector.hpp"
#include <cstdlib> 
#include <iostream>

Vector::Vector(){
    for (std::size_t idx = 0; idx < Vector::getCapacity(); ++idx){
        this->m_data[idx] = rand();
    }
}

Vector::~Vector(){
    for (std::size_t idx = 0; idx < Vector::getCapacity(); ++idx){
        this->m_data[idx] = 0;    
    }
}

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
}

std::size_t Vector::getSize(){
    return this->m_size;
}

std::size_t Vector::getCapacity(){
    return this->m_capacity;
}

void Vector::insert(std::size_t idx, int element){
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

void Vector::pushFront(int element){
    m_size = m_size + 1;

    for (std::size_t idx = 0; idx < this->getSize()-2; ++idx){
        this->m_data[idx + 1] = this->m_data[idx];
    }

    this->m_data[0] = element;
}

void Vector::pushBack(int element){
    m_size = m_size + 1;
    this->m_data[m_size] = element;
}

int Vector::getFront(){
    return this->m_data[0];
}

int Vector::getBack(){
    return this->m_data[this->m_size-1];
}

void Vector::setFront(int element){
    this->m_data[0] = element;
}

void Vector::setBack(int element){
    this->m_data[m_size] = element;
}

void Vector::clear(){
    for (std::size_t idx = 0; idx < m_size-1; ++idx){
        this->m_data[idx] = 0;
    }
}

bool Vector::empty(){
    bool flag = true;
    int idx = 0;

    while ((idx < m_size - 1) || (flag == true)){
        if (this->m_data[idx] == 0)
            idx = idx + 1;
        else
            flag = false;
    }

    return flag;
}