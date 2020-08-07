#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include <cstddef>

template <typename TValue> 
class ListNode{
    public:
        ListNode(ListNode* prev, ListNode* next, TValue data);
        ListNode(const ListNode& rhs) = default;
        ~ListNode();

        ListNode& operator=(const ListNode& rhs);

        ListNode* getPrev();
        void setPrev(ListNode* prev);

        ListNode* getNext();
        void setNext(ListNode* next);

        TValue getData();
        void setData(ListNode* data);
        
        template <typename UValue>
        friend std::ostream& operator<<(std::ostream& os, const ListNode<UValue>& task); 

    private:
        ListNode* m_prev;
        ListNode* m_next;
        TValue m_data;    
};

#include "ListNode.tpp"

#endif// LIST_NODE