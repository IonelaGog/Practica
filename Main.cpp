#include "Vector.hpp"
#include "List.hpp"
#include "ListNode.hpp"
#include <cstdlib>

int main(){
    Vector vec;
    std::size_t end = vec.getCapacity();

    for (std::size_t idx = 0; idx < end; ++idx){
        vec.setElement(idx, std::rand());
    }

    int sum = 0;

    for (std::size_t idx = 0; idx < end; ++idx){
        sum += vec.getElement(idx);
    }
   return sum;
}