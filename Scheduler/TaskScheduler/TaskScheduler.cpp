#include "TaskManager.h"
#include <iostream>
#include <vector>

int main()
{
    std::vector<Task> tasks;
    addTask(tasks, "task1", time(nullptr));
    addTask(tasks, "task2", time(nullptr));
    addTask(tasks, "task3", time(nullptr));

    viewTasks(tasks);

    markTaskCompleted(tasks, 3);

    viewTasks(tasks);

    removeTask(tasks, 1);

    resetIds(tasks);

    viewTasks(tasks);

    markTaskCompleted(tasks, 1);

    viewTasks(tasks);
}