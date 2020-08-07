#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <ostream>
#include "ListNode.hpp"
#include "ListIterator.hpp"

template <typename TValue>
class List{
    public:
        using TIterator = ListIterator<TValue>;

        List();
        List(const List& rhs);
        List(const List&& rhs);
        ~List();

        std::size_t getSize();

        List& operator=(const List& rhs);
        List& operator=(const List&& rhs);

        void insert(TIterator pos, TValue element);

        void pushFront(TValue element);
        void pushBack(TValue element);

        void erase(TIterator pos);
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

        auto begin();
        auto end();
        
    private:
        std::size_t m_size;
        ListNode<TValue>* m_head;
        ListNode<TValue>* m_tail;  
};

#include "List.tpp"

#endif//LIST_HPP