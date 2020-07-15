#ifndef TASK_HPP
#define TASK_HPP

#include <cstddef>
#include <string>
#include <ostream>

class Task{
    public:
        Task(std::string description, int8_t priority);

        std::string getDescription();
        int8_t getPriority();

        bool operator<(const Task& rhs);

        friend std::ostream& operator<<(std::ostream& os, const Task& task);

    private:
        std::string m_description;
        int8_t m_priority;
};

#include "Task.tpp"

#endif//TASK_HPP