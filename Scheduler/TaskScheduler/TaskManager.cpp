#include "TaskManager.h"

#include <iostream>
#include <iomanip>

void addTask(std::vector<Task>& tasks, const std::string& description, time_t dueDate) {
	int newId = tasks.empty() ? 1 : tasks.back().getId() + 1;

	tasks.push_back(Task(newId, description, dueDate));
}

void viewTasks(const std::vector<Task>& tasks) {
	if (tasks.empty()) {
		std::cout << "No tasks to display." << std::endl;
	}

	std::cout << std::setw(5) << "ID" << std::setw(25) << "Description" << std::setw(20) << "Due Date" << std::setw(15) << "Completed" << std::endl;
	std::cout << std::string(65, '-') << std::endl;

	for (const Task& task : tasks) {
		std::cout << std::setw(5) << task.getId() << std::setw(25) << task.getDescription() << std::setw(20) << task.getDueDate() << std::setw(15) << (task.getIsComplited()  ? "Yes" : "No") << std::endl;
	}
}

void markTaskCompleted(std::vector<Task>& tasks, int taskId) {
	auto targetedTask = std::find_if(tasks.begin(), tasks.end(), [taskId](Task& task) {
		return task.getId() == taskId;
		});

	if (targetedTask != tasks.end()) {
		targetedTask->setIsCompleted(true);
	}
}

void removeTask(std::vector<Task>& tasks, int taskId) {
	auto targetedTask = std::find_if(tasks.begin(), tasks.end(), [taskId](Task& task) {
		return task.getId() == taskId;
		});
	
	if (targetedTask != tasks.end()) {
		tasks.erase(targetedTask);
	}
}

void resetIds(std::vector<Task>& tasks) {
	if (tasks.empty()) {
		std::cout << "There are no tasks saved." << std::endl;
	}

	int newId = 1;

	for (Task& task : tasks) {
		task.setId(newId);
		newId++;
	}
}
