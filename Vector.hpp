#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

template <typename TValue>
class Vector{
    public:
        Vector();
        Vector(const Vector& rhs);
        ~Vector();

        Vector& operator=(const Vector& rhs);

        std::size_t getSize();
        std::size_t getCapacity();

        void insert(std::size_t idx, TValue element);
        void pushFront(TValue element);
        void pushBack(TValue element);

        void erase(std::size_t idx);
        void popFront();
        void popBack();

        //int getElement(std::size_t idx); - replaced by: 
        const TValue& operator[](std::size_t idx) const;

        TValue& getFront();
        TValue& getBack();

        //void setElement(std::size_t idx, int element); - replaced by:
        TValue& operator[](std::size_t idx);

        void setFront(TValue element);
        void setBack(TValue element);

        void clear();
        bool empty();

        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, const Vector<TValue>& vec);

    private:
        std::size_t m_capacity;
        std::size_t m_size;
        TValue* m_data;

        void reserve(std::size_t newCapacity);
};

#include "Vector.tpp"

#endif// VECTOR_HPP