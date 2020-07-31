#ifndef TASKARGUMENT_HPP
#define TASKARGUMENT_HPP

#include <cstddef>

class TaskArgument{
    public:
        int op1;
        int op2;

        TaskArgument(int op1, int op2){
            this->op1 = op1;
            this->op2 = op2;
        }
};

#endif