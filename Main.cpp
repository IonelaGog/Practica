#include "Vector.hpp"
#include "List.hpp"
#include "ListNode.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "SynchPriorityQueue.hpp"
#include "Task.hpp"
#include "TaskScheduler.hpp"
#include "Algorithms.hpp"

#include <iostream>


int main()
{
  TaskScheduler scheduler(9);

  TaskArgument ta1(8, 6);
  TaskArgument ta2(9, 3);

  auto future1 = scheduler.schedule(ta1, 2);
  auto future2 = scheduler.schedule(ta2, 3);

  std::cout << future1.get().sum << std::endl;
  

}