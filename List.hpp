#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <ostream>
#include "ListNode.hpp"

template <typename TValue>
class List{
    public:
        List();
        List(const ListNode& rhs);
        ~List();

        std::size_t getSize();

        ListNode& operator=(const ListNode& rhs);

        void insert(std::size_t idx, TValue element);
        void pushFront(TValue element);
        void pushBack(TValue element);

        void erase(std::size_t idx);
        void popFront();
        void popBack();

        //int getElement(std::size_t idx); - replaced by:
        const TValue& operator[](std::size_t idx) const;
        TValue getFront();
        TValue getBack();

        //void setElement(std::size_t idx, int element); - replaced by:
        TValue& operator[](std::size_t idx);
        void setFront(TValue element);
        void setBack(TValue element);

        void clear();
        bool isEmpty();

        friend std::ostream& operator<<(std::ostream& os, const List& task); 

        ListIterator<TValue> begin();
        ListIterator<TValue> end();
        
    private:
        std::size_t m_size;
        ListNode<TValue>* m_head;
        ListNode<TValue>* m_tail;  
};

#include "List.tpp"

#endif//LIST_HPP