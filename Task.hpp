#ifndef TASK_HPP
#define TASK_HPP

#include <cstddef>
#include <string>
#include <ostream>

#include "TaskArgument.hpp"
#include "TaskResult.hpp"

class Task{
    public:
        Task(std::string description, int8_t priority);

        std::string getDescription();
        int8_t getPriority();

        bool operator<(const Task& rhs);
        TaskResult operator()(TaskArgument rez);

        Task(std::int64_t prio, function <TaskResult(TaskArgument)> func); 

        friend std::ostream& operator<<(std::ostream& os, const Task& task);

    private:
        std::string m_description;
        int64_t m_priority;
        function <TaskResult(TaskArgument)> m_function;
};

#include "Task.tpp"

#endif//TASK_HPP