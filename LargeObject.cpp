#include "LargeObject.hpp"
#include <cstdlib>

LargeObject::LargeObject(){
    for (std::size_t idx = 0; idx < LARGE_OBJECT_SIZE; ++idx){
        m_data[idx] = rand();
    }
}

LargeObject::~LargeObject(){
    for (std::size_t idx = 0; idx < LARGE_OBJECT_SIZE; ++idx){
        m_data[idx] = 0;
    }
}