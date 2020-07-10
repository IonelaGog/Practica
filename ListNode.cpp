#include "List.hpp"
#include <cstdlib> 
#include <iostream>

ListNode::ListNode(ListNode*prev, ListNode* next, int data){
    m_data = data;  
    m_prev = prev;
    m_next = next;
}

ListNode::~ListNode(){
    if(m_next != NULL){
        m_next->m_prev = m_prev;
    }

    if(m_prev != NULL){
        m_prev->m_next = m_next;
    } 
}

ListNode* ListNode::getPrev(){
    return this->m_prev;
}

void ListNode::setPrev(ListNode* prev){
    this->m_prev = prev;
}

ListNode* ListNode::getNext(){
    return this->m_next;
}

void ListNode::setNext(ListNode* next){
    this->m_next = next;
}

int ListNode::getData(){
    return this->m_data;
}

void ListNode::setData(ListNode* data){
    this->m_prev = data->m_prev;
    this->m_next = data->m_next;
    this->m_data = data->m_data;
}