#ifndef TASKMANAGER_H

#define TASKMANAGER_H

#include "Task.h"
#include <string>
#include <vector>
#include <ctime>

void addTask(std::vector<Task>& tasks, const std::string& description, time_t dueDate);

void viewTasks(const std::vector<Task>& tasks);

void markTaskCompleted(std::vector<Task>& tasks, int taskId);

void removeTask(std::vector<Task>& tasks, int taskId);

void resetIds(std::vector<Task>& tasks);

void saveTaskToFile(const std::vector<Task>& tasks, const std::string& filename);

void loadTaskFromFile(std::vector<Task>& tasks, const std::string& filename);

#endif