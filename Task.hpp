#ifndef TASK_HPP
#define TASK_HPP

#include <future>
#include <string>
#include <cstddef>
#include <ostream>

#include "TaskArgument.hpp"
#include "TaskResult.hpp"
#include "Function.hpp"

class Task
{
public:
    Task() = default;

    Task(std::int64_t prio, std::packaged_task<TaskResult()> &&pt);

    std::int64_t getPriority();

    bool operator<(const Task &rhs);
    // bool operator<(Task &&rhs);

    void operator()();

    friend std::ostream &operator<<(std::ostream &os, const Task &task);

private:
    int64_t m_priority;
    Function<void()> m_function;
};

#include "Task.tpp"

#endif //TASK_HPP