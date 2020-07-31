#include <cstddef>
#include <thread>
#include <mutex>
#include <future>
#include <functional>
#include <iostream>

#include "TaskScheduler.hpp"
#include "SynchPriorityQueue.hpp"
#include "Task.hpp"

TaskScheduler::TaskScheduler(std::size_t count)
{
    for (std::size_t idx = 0; idx < count; ++idx)
    {
        m_threads.pushBack(std::thread(&TaskScheduler::processTasks, this));
    }
}

TaskScheduler::~TaskScheduler()
{
    m_stop = true;
    std::size_t len = m_threads.getSize();

    for (std::size_t cnt = 0; cnt < len; cnt++)
    {
        m_threads[cnt].join();
    }
}

std::future<TaskResult> TaskScheduler::schedule(TaskArgument arg, std::int64_t prio)
{
    auto lambda = [arg]() {
        TaskResult tkRes;
        tkRes.sum = arg.op1 + arg.op2;

        return tkRes;
    };

    std::packaged_task<TaskResult()> packagedTask(lambda);
    std::future<TaskResult> futureTask = packagedTask.get_future();

    Task task(prio, std::move(packagedTask));

    m_task.push(std::move(task));

    return futureTask;
}

void TaskScheduler::processTasks()
{
    while (m_stop != true)
    {
        Task tk;

        if (m_task.tryPop(tk))
        {
            tk();
        }
    }
}

void TaskScheduler::stop()
{
    m_stop = true;
}