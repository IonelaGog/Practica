#include "List.hpp"
#include "ListIterator.hpp"
#include <cstdlib>
#include <iostream>

template <typename TValue>
List<TValue>::List(){
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

template <typename TValue>
List<TValue>::List(const List<TValue>& rhs){
    ListNode<TValue>* cap = m_head;

    while (cap != NULL){
        this->cap.m_data = rhs.m_data;
        this->cap.m_prev = rhs.m_prev; 
        this->cap.m_next = rhs.m_next;

        cap = cap->getNext();
    }
}

template <typename TValue>
List<TValue>::List(const List&& rhs){
    m_size = rhs.m_size;
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
   
    rhs.m_size = 0;
    rhs.m_head = NULL;
    rhs.m_tail = NULL;
}

template <typename TValue>
List<TValue>::~List(){
    ListNode<TValue>* cap = m_head;
    ListNode<TValue>* temp;

    while (cap != NULL){
        temp = cap;
        cap = cap->getNext();
        delete temp;
    }
    m_head = NULL;
    m_tail = NULL;
}

template <typename TValue>
std::size_t List<TValue>::getSize(){
    return this->m_size;
}

template <typename TValue>
void List<TValue>::insert(TIterator pos, TValue element){
    ListNode<TValue>* nod = new ListNode(NULL,NULL,element);
    ListNode<TValue>* cap = m_head;

    if (pos == begin()){
        pushFront(element);
    }
    else if (pos == end()){
            pushBack(element);
    }

    cap = m_head;
    for (auto it = begin(); it!= pos; ++it){
        cap = cap->getNext();
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

template <typename TValue>
void List<TValue>::popFront()
{
    ListNode<TValue>* cap = m_head;
    m_head = m_head->getNext();
    delete cap;
    --m_size;
}

template <typename TValue>
void List<TValue>::popBack(){
    if(m_head != NULL){
        ListNode<TValue>* cap = m_tail;
        m_tail = m_tail->getPrev();
        delete cap;
        --m_size;
    }
}

template <typename TValue>
const TValue& List<TValue>::operator[](std::size_t idx) const{
    ListNode<TValue>* cap = m_head;
    
    while(idx){
        cap = cap->getNext();
        --idx;
    }
    return cap->getData(); 
}

template <typename TValue>
TValue List<TValue>::getFront(){
    return m_head->getData();
}

template <typename TValue>
TValue List<TValue>::getBack(){
    return m_tail->getData();
}

template <typename TValue>
TValue& List<TValue>::operator[](std::size_t idx){
    ListNode<TValue>* cap = m_head;
    
    while(idx){
        cap = cap->getNext();
        --idx;
    }
    return cap->getData(); 
}

template <typename TValue>
ListNode<TValue>& ListNode<TValue>::operator=(const ListNode<TValue>& rhs){
    m_prev = rhs.m_prev;
    m_next = rhs.m_next;
    m_data = rhs.m_data;
    
    return *this;
}

template <typename TValue>
List<TValue>& List<TValue>::operator=(const List&& rhs){
    m_size = rhs.m_size;
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
    
    rhs.m_size = 0;
    rhs.m_head = NULL;
    rhs.m_tail = NULL;
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
    ListNode<TValue>* cap1;

    while (cap != NULL){
        cap1 = cap->getNext();
        delete cap;
        cap = cap1;
    }
    m_size = 0;
    m_head = 0;
    m_tail = 0;
}

template <typename TValue>
bool List<TValue>::isEmpty(){
  return m_size == 0;
}

template<typename UValue>
std::ostream& operator<<(std::ostream& os, const List<UValue>& task){
   ListNode<UValue>* cap = task.m_head;

   while(cap != NULL){
       os << cap->getData() << " ";
       cap = cap->getNext();
   }
    os << "\n";
    return os;
}

template <typename TValue>
auto List<TValue>::begin(){
    return ListIterator<TValue>(m_head);
}

template <typename TValue>
auto List<TValue>::end(){
    return ListIterator<TValue>(m_tail);
}