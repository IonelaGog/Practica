#ifndef TASKSCHEDULER_HPP
#define TASKSCHEDULER_HPP

#include <cstddef>
#include <thread>
#include <atomic>
#include <future>

#include "TaskArgument.hpp"
#include "TaskResult.hpp"
#include "SynchPriorityQueue.hpp"
#include "Task.hpp"
#include "Vector.hpp"

class TaskScheduler{
    public:
        TaskScheduler(std::size_t count);
        ~TaskScheduler();

        std::future<TaskResult> schedule(TaskArgument arg, std::int64_t prio);
        void stop();

    private:
        SynchPriorityQueue<std::packaged_task<TaskResult()>> m_task;
        Vector<std::thread> m_threads;
        std::atomic<bool> m_stop;

        void processTasks();
};

#endif //TASKSCHEDULER_HPP