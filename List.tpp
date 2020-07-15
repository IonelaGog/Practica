#include "List.hpp"
#include <cstdlib>
#include <iostream>

template <typename TValue>
List<TValue>::List(){
    ListNode<TValue>* m_head = NULL;
    ListNode<TValue>* m_tail = NULL;
    std::size_t m_size = 0;
}

template <typename TValue>
List<TValue>::~List(){
    ListNode<TValue>* cap = m_head;

    while (cap != NULL){
        temp = cap;
        cap = cap->getNext();
        delete(temp);
    }
    m_head = NULL;
    m_tail = NULL;
}

template <typename TValue>
std::size_t List<TValue>::getSize(){
    return this->m_size;
}

template <typename TValue>
void List<TValue>::insert(std::size_t idx, TValue element){
    ListNode<TValue>* nod = new ListNode(NULL,NULL,element);
    ListNode<TValue>* cap = m_head;

    if (idx == 0)
        pushFront(element);
    else if (idx == m_size)
            pushBack(element);

    while (idx > 0){
        cap = cap->getNext();
        idx = idx - 1;
    }     

    cap->getPrev()->setNext(nod);
    nod->setPrev(cap->getPrev());
    cap->setPrev(nod);
    nod->setNext(cap);

    m_size = m_size + 1;
}

template <typename TValue>
void List<TValue>::pushFront(TValue element){
    ListNode<TValue>* nod = new ListNode(NULL, NULL, element);
    ListNode<TValue>* cap = m_head;
    ListNode<TValue>* coada = m_tail;

    if (cap == NULL){
        cap = nod;
        coada = nod;
    }
    else{
        nod->setNext(cap);
        cap->setPrev(nod);
        coada->setData(nod);
    }
    m_size = m_size + 1;
}

template <typename TValue>
void List<TValue>::pushBack(TValue element){
    ListNode<TValue>* nod = new ListNode(NULL, NULL, element);
    ListNode<TValue>* cap = m_head;
    ListNode<TValue>* coada = m_tail;

    if (cap == NULL){
        cap = nod;
        coada = nod;
    }
    else if (cap == coada){
        cap->setNext(nod);
        nod->setPrev(cap);
        coada = nod;
    }

    while(cap->getNext() != NULL){
       cap = cap->getNext();
    }

    cap->setNext(nod);
    nod->setPrev(cap);
    coada = nod;

    m_size = m_size + 1;
}
/*
int List::getElement(std::size_t idx){
    ListNode* cap = m_head;
    std::size_t count = 0;
    int nr = 0;

    if ((idx < 0) || (idx > this->m_size-1)){
        std::cout << "The position isn't valid" << std::endl;
        return 1;
    }
    else{
        while ((cap != NULL) || (count != idx)){
            if (count == idx)
                nr = (int)cap->getData();
            count = count + 1;    
        }
        return nr;
    }    
}*/

template <typename TValue>
const TValue& List<TValue>::operator[](std::size_t idx) const{

}

template <typename TValue>
TValue List<TValue>::getFront(){
    return (TValue)this->m_head;
}

template <typename TValue>
TValue List<TValue>::getBack(){
    return (TValue)this->m_tail;
}

/*
void List::setElement(std::size_t idx, int element){
    ListNode* cap = m_head;
    std::size_t count = 0;

    if ((idx < 0) || (idx > this->m_size-1))
        std::cout << "The position isn't valid" << std::endl;
    else
    {
        while (cap != NULL){
            if (count == idx)
                cap->setData((ListNode*)element);
            cap = cap->getNext();  
            count = count + 1;  
        }
    }
}*/

template <typename TValue>
TValue& List<TValue>::operator[](std::size_t idx){

}

template <typename TValue>
ListNode<TValue>& ListNode<TValue>::operator=(const ListNode<TValue>& rhs){
    m_prev = rhs.m_prev;
    m_next = rhs.m_next;
    m_data = rhs.m_data;
    
    return *this;
}

template <typename TValue>
void List<TValue>::setFront(TValue element){
    this->m_head = (ListNode<TValue>*)element;
}

template <typename TValue>
void List<TValue>::setBack(TValue element){
    this->m_tail = (ListNode<TValue>*)element;
}

template <typename TValue>
void List<TValue>::clear(){
    ListNode<TValue>* cap = m_head;

    while (cap != NULL){
        cap = 0;
        cap = cap->getNext();
    }
}

template <typename TValue>
bool List<TValue>::isEmpty(){
    ListNode* cap = m_head;
    bool flag = false;
    std::size_t count = 0;

    while ((cap != NULL) || (count < this->m_size-1)){
        flag = true;
        cap = cap->getNext();
        count = count + 1;
    }
    return flag;
}