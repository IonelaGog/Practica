#include "Task.hpp"
#include <cstdlib>
#include <iostream>

Task::Task(std::int64_t prio, std::packaged_task<TaskResult()> &&pt) : m_priority(prio), m_function(std::move(pt)) {}

std::int64_t Task::getPriority()
{
    return m_priority;
}

bool Task::operator<(const Task &rhs)
{
    return m_priority < rhs.m_priority;
}

// bool Task::operator<(Task &&rhs)
// {
//     return m_priority < rhs.m_priority;
// }

std::ostream &operator<<(std::ostream &os, const Task &task)
{
    os << "priority: " << task.m_priority << "\n";

    return os;
}

void Task::operator()()
{
    m_function();
}
