#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include <cstdlib>
#include <cstddef>

template <typename TValue>
class ListIterator{
    public:

        ListIterator(ListNode<TValue>* value);
        ListIterator(const ListIterator& rhs);

        ListIterator& operator=(const ListIterator& rhs);

        bool operator!=(const ListIterator& rhs);
        bool operator<(const ListIterator& rhs);

        ListIterator& operator++();
        ListIterator& operator--();

        ListIterator& operator+=(std::size_t difference);
        ListIterator& operator-=(std::size_t difference);

        ListIterator& operator+(std::size_t difference);
        ListIterator& operator-(std::size_t difference);

        TValue operator*();

    private:    
        ListNode<TValue>* m_value;
};

#include "ListIterator.tpp"

#endif //LISTITERATOR_HPP