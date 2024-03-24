#ifndef TASK_H

#define TASK_H


#include <iostream>
#include <string>
#include <ctime>

class Task {
private:
	int id;
	time_t dueDate;
	bool isCompleted;
	std::string description;

public:
	Task(int id, const std::string& description, time_t dueDate, bool isCompleted = false);

	// Getters
	int getId() const;
	time_t getDueDate() const;
	bool getIsCompleted() const;
	std::string getDescription() const;

	// Setters
	void setId(const int id);
	void setDueDate(const time_t dueDate);
	void setIsCompleted(const bool isCompleted);
	void setDescription(const std::string& description);
};

std::ostream& operator<<(std::ostream& os, const Task& task);

#endif