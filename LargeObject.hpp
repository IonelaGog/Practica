#include <cstddef>
#include <cstdint>

constexpr std::size_t LARGE_OBJECT_SIZE = 1024;

struct LargeObject{
    LargeObject();
    ~LargeObject();

    std::int8_t m_data[LARGE_OBJECT_SIZE];
};