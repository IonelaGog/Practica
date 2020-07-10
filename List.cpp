#include "List.hpp"
#include <cstdlib>
#include <iostream>

List::List(){
    ListNode* m_head = NULL;
    ListNode* m_tail = NULL;
    std::size_t m_size = 0;
}

List::~List(){
    ListNode* temp;
    ListNode* cap = m_head;

    while (cap != NULL){
        temp = cap;
        cap = cap->getNext();
        delete(temp);
    }
    m_head = NULL;
    m_tail = NULL;
}

std::size_t List::getSize(){
    return this->m_size;
}

void List::insert(std::size_t idx, int element){
    ListNode* nod = new ListNode(NULL,NULL,element);
    ListNode* cap = m_head;

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

void List::pushFront(int element){
    ListNode* nod = new ListNode(NULL, NULL, element);
    ListNode* cap = m_head;
    ListNode* coada = m_tail;

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

void List::pushBack(int element){
    ListNode* nod = new ListNode(NULL, NULL, element);
    ListNode* cap = m_head;
    ListNode* coada = m_tail;

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
        }
        return nr;
    }    
}

int List::getFront(){
    return (int)this->m_head;
}

int List::getBack(){
    return (int)this->m_tail;
}

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
        }
    }
}

void List::setFront(int element){
    this->m_head = (ListNode*)element;
}

void List::setBack(int element){
    this->m_tail = (ListNode*)element;
}

void List::clear(){
    ListNode* cap = m_head;

    while (cap != NULL){
        cap = 0;
        cap = cap->getNext();
    }
}

bool List::empty(){
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