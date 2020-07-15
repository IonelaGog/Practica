#include "List.hpp"
#include <cstdlib> 
#include <iostream>

template <typename TValue>
ListNode<TValue>::ListNode(ListNode*prev, ListNode* next, TValue data){
    m_data = data;  
    m_prev = prev;
    m_next = next;
}

template <typename TValue>
ListNode<TValue>::ListNode(const ListNode& rhs){
    
}

template <typename TValue>
ListNode<TValue>::~ListNode(){
    if(m_next != NULL){
        m_next->m_prev = m_prev;
    }

    if(m_prev != NULL){
        m_prev->m_next = m_next;
    } 
}

template <typename TValue>
ListNode<TValue>* ListNode<TValue>::getPrev(){
    return this->m_prev;
}

template <typename TValue>
void ListNode<TValue>::setPrev(ListNode* prev){
    this->m_prev = prev;
}

template <typename TValue>
ListNode<TValue>* ListNode<TValue>::getNext(){
    return this->m_next;
}

template <typename TValue>
void ListNode<TValue>::setNext(ListNode* next){
    this->m_next = next;
}

template <typename TValue>
TValue ListNode<TValue>::getData(){
    return this->m_data;
}

template <typename TValue>
void ListNode<TValue>::setData(ListNode* data){
    this->m_prev = data->m_prev;
    this->m_next = data->m_next;
    this->m_data = data->m_data;
}