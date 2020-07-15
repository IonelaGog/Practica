#include "Task.hpp"
#include <cstdlib> 
#include <iostream>

Task::Task(std::string description, int8_t priority){
    m_description = description;
    m_priority = priority;
}

std::string Task::getDescription(){
    return m_description;
}

int8_t Task::getPriority(){
    return m_priority;
}

bool Task::operator<(const Task& rhs){
    if(m_priority < rhs.m_priority){
        return true;
    }
    else 
        return false;
}

std::ostream& operator<<(std::ostream& os, const Task& task){
    os << "description: " << task.m_description << "\n";
    os << "priority: " << task.m_priority << "\n";

    return os;
}