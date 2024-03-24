#include "TaskManager.h"
#include "FileUtils.h"
#include <iostream>
#include <vector>

int main()
{
    std::string filename = "tasks.txt";
    std::string filepath = getUniversalFilePath(filename);

    std::cout << filepath << std::endl;

    std::vector<Task> tasks;
    addTask(tasks, "task1", time(nullptr));
    addTask(tasks, "task2", time(nullptr));
    addTask(tasks, "task3", time(nullptr));

    markTaskCompleted(tasks, 3);

    viewTasks(tasks);

    saveTaskToFile(tasks, filepath);

    loadTaskFromFile(tasks, filepath);

    viewTasks(tasks);

}