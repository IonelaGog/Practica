#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "VectorIterator.hpp"

#include <cstddef>

template <typename TValue>
class Vector
{
public:
    using TIterator = VectorIterator<TValue>;

    Vector();
    Vector(const Vector &rhs);
    Vector(const Vector &&rhs);
    ~Vector();

    Vector &operator=(const Vector &rhs);
    Vector &operator=(Vector &&rhs);

    std::size_t getSize();
    std::size_t getCapacity();

    void insert(TIterator pos, const TValue& element);
    void insert(TIterator pos, TValue&& element);

    void pushFront(TValue element);
    void pushBack(const TValue &element);
    void pushBack(TValue &&element);

    void erase(TIterator pos);
    void popFront();
    void popBack();

    //int getElement(std::size_t idx); - replaced by:
    const TValue &operator[](std::size_t idx) const;

    TValue &getFront();
    TValue &getBack();

    //void setElement(std::size_t idx, int element); - replaced by:
    TValue &operator[](std::size_t idx);

    void setFront(TValue element);
    void setBack(TValue element);

    void clear();
    bool isEmpty();

    template <typename T>
    friend std::ostream &operator<<(std::ostream &os, const Vector<TValue> &task);

    void reserve(std::size_t newCapacity);
    void resize(std::size_t newSize);

    TIterator begin();
    TIterator end();

private:
    std::size_t m_capacity;
    std::size_t m_size;
    TValue *m_data;
};

#include "Vector.tpp"

#endif // VECTOR_HPP