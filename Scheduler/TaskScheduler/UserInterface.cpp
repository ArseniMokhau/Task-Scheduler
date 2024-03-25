
#include "UserInterface.h"
#include "TaskManager.h"
#include "TimeUtils.h"
#include "FileUtils.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

void startUserInterface(std::vector<Task>& tasks)
{
	int choice;
	do {
		std::cout << "Menu:" << std::endl;
		std::cout << "1. Add Task" << std::endl;
		std::cout << "2. View Tasks" << std::endl;
		std::cout << "3. Mark Tasks Completed" << std::endl;
		std::cout << "4. Delete Task" << std::endl;
		std::cout << "5. Reset Task ID's" << std::endl;
		std::cout << "6. Save Changes" << std::endl;
		std::cout << "7. Exit" << std::endl;
		std::cout << "Enter your choice: " << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			addTaskFromUserInput(tasks);
			break;
		case 2:
			viewTasks(tasks);
			break;
		case 3:
			markTaskCompletedFromUserInput(tasks);
			break;
		case 4:
			removeTaskFromUserInput(tasks);
			break;
		case 5:
			resetIds(tasks);
			break;
		case 6:
			saveChanges(tasks);
			break;
		case 7:
			exitTaskScheduler(tasks);
			break;
		default:
			break;
		}
	} while (choice != 7);
}


void addTaskFromUserInput(std::vector<Task>& tasks) {
	std::string description;
	std::string dateString;
	time_t dueDate;
	// Prompt for task details and input handling
	std::cout << "Enter task description: ";
	std::cin.ignore(); // Ignore previous newline character
	std::getline(std::cin, description);

	std::cout << "Enter date: ";
	std::getline(std::cin, dateString);

	if (validateDateTimeFormat(dateString)) {
		dueDate = convertStringToTimeT(dateString);

		addTask(tasks, description, dueDate);
	}
	else {
		std::cout << "Incorrect date-time format" << std::endl;
	}
}

void markTaskCompletedFromUserInput(std::vector<Task>& tasks) {
	int selectedTask;
	std::cout << "Enter task id: ";
	std::cin.ignore(); // Ignore previous newline character
	std::cin >> selectedTask;
	markTaskCompleted(tasks, selectedTask);
}

void removeTaskFromUserInput(std::vector<Task>& tasks) {
	int selectedTask;
	std::cout << "Enter task id: ";
	std::cin.ignore(); // Ignore previous newline character
	std::cin >> selectedTask;
	removeTask(tasks, selectedTask);
}

void exitTaskScheduler(std::vector<Task>& tasks) {
	exit;
}

void saveChanges(std::vector<Task>& tasks) {
	std::string filename = "tasks.txt";
	std::string filepath = getUniversalFilePath(filename);

	std::cout << filepath << std::endl;

	saveTaskToFile(tasks, filepath);
}