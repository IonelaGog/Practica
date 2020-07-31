#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <cstddef>

template <typename TValue>
class VectorIterator{
    public:
        using TIterator = VectorIterator<TValue>::TIterator;

        VectorIterator(TValue* value);
        VectorIterator(const VectorIterator& rhs);

        VectorIterator& operator=(const VectorIterator& rhs);

        bool operator!=(const VectorIterator& rhs);
        bool operator<(const VectorIterator& rhs);

        VectorIterator& operator++();
        VectorIterator& operator--();

        VectorIterator& operator+=(std::size_t difference);
        VectorIterator& operator-=(std::size_t difference);

        VectorIterator& operator+(std::size_t difference);
        VectorIterator& operator-(std::size_t difference);

        TValue operator*();

    private:
        TValue* m_value;    
};

#include "VectorIterator.tpp"

#endif //VECTORITERATOR_HPP