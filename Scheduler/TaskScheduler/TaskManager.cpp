#include "TaskManager.h"
#include "TimeUtils.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

void addTask(std::vector<Task>& tasks, const std::string& description, time_t dueDate) {
	int newId = tasks.empty() ? 1 : tasks.back().getId() + 1;

	tasks.emplace_back(newId, description, dueDate);
}

void viewTasks(const std::vector<Task>& tasks) {
	if (tasks.empty()) {
		std::cout << "No tasks to display." << std::endl;
		return;
	}

	std::cout << std::setw(5) << "ID" << std::setw(25) << "Description" << std::setw(20) << "Due Date" << std::setw(15) << "Completed" << std::endl;
	std::cout << std::string(65, '-') << std::endl;

	for (const Task& task : tasks) {
		std::cout << std::setw(5) << task.getId() << std::setw(25) << task.getDescription() << std::setw(20) << convertTimeTToString(task.getDueDate()) << std::setw(15) << (task.getIsCompleted()  ? "Yes" : "No") << std::endl;
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

void saveTaskToFile(const std::vector<Task>& tasks, const std::string& filename)
{
	std::ofstream outputFile(filename);
	if (outputFile.is_open()) {
		outputFile.clear();

		for (const Task& task : tasks) {
			outputFile << "\"" << task.getId() << "\","
				<< "\"" << task.getDescription() << "\","
				<< "\"" << task.getDueDate() << "\","
				<< "\"" << task.getIsCompleted() << "\"\n";
		}

		outputFile.close();
	}
	else {
		std::cerr << "Error: Could not open file: " << filename << std::endl;
		return;
	}
}

void loadTaskFromFile(std::vector<Task>& tasks, const std::string& filename)
{
	std::ifstream inputFile(filename);

	if (inputFile.is_open()) {

		tasks.clear();

		std::string line;

		while (std::getline(inputFile, line)) {
			std::stringstream ss(line);
			std::vector<std::string> tokens;

			std::string token;
			while (std::getline(ss, token, ',')) {
				if (!token.empty() && token.front() == '"') {
					token = token.substr(1, token.size() - 2);
				}
				tokens.push_back(token);
			}

			if (tokens.size() == 4) {
				try {
					int id = std::stoi(tokens[0]);
					std::string description = tokens[1];
					time_t dueDate = std::stol(tokens[2]);
					bool isCompleted = (tokens[3] == "1");
					tasks.emplace_back(id, description, dueDate, isCompleted);
				}
				catch (const std::exception& e) {
					std::cerr << "Error parsing line: " << line << std::endl;
				}
			}
			else {
				std::cerr << "Invalid line format: " << line << std::endl;
			}
		}
		inputFile.close();
	}
	else {
		std::cerr << "Error: Could not open file: " << filename << std::endl;
		return;
	}
}

