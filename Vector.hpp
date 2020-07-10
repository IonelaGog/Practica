#include <cstddef>

class Vector{
    public:
        Vector();
        ~Vector();

        std::size_t getSize();
        std::size_t getCapacity();

        void insert(std::size_t idx, int element);
        void pushFront(int element);
        void pushBack(int element);

        int getElement(std::size_t idx);

        int getFront();
        int getBack();

        void setElement(std::size_t idx, int element);
        void setFront(int element);
        void setBack(int element);

        void clear();
        bool empty();

    private:
        std::size_t m_capacity;
        std::size_t m_size;
        int* m_data;

        void reserve(std::size_t newCapacity);
};