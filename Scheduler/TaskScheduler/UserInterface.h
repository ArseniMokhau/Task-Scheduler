#ifndef USER_INTERFACE_H

#define USER_INTERFACE_H

#include <vector>
#include "Task.h"

void startUserInterface(std::vector<Task>& tasks);

void addTaskFromUserInput(std::vector<Task>& tasks);

void markTaskCompletedFromUserInput(std::vector<Task>& tasks);

void removeTaskFromUserInput(std::vector<Task>& tasks);

void exitTaskScheduler(std::vector<Task>& tasks);

void saveChanges(std::vector<Task>& tasks);

time_t convertStringToTimeT(const std::string& dateTimeString);

#endif
