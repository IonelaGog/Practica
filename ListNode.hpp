#ifndef LIST_NODE.HPP
#define LIST_NODE.HPP

#include <cstddef>

template <typename TValue> 
class ListNode{
    public:
        ListNode(ListNode* prev, ListNode* next, TValue data);
        ListNode(const ListNode& rhs);
        ~ListNode();

        ListNode& operator=(const ListNode& rhs);

        ListNode* getPrev();
        void setPrev(ListNode* prev);

        ListNode* getNext();
        void setNext(ListNode* next);

        TValue getData();
        void setData(ListNode* data);
        
        template <typename TValue>
        friend std::ostream& operator<<(std::ostream& os, const ListNode<TValue>& task); 

    private:
        ListNode* m_prev;
        ListNode* m_next;
        TValue m_data;    
};

#include "ListNode.tpp"

#endif// LIST_NODE