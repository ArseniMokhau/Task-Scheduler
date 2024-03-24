#ifndef TASK_H

#define TASK_H

#include <string>
#include <ctime>

class Task {
private:
	int id;
	time_t dueDate;
	bool isCompleted;
	std::string description;

public:
	Task(int id, const std::string& description, time_t dueDate);

	// Getters
	int getId() const;
	time_t getDueDate() const;
	bool getIsComplited() const;
	std::string getDescription() const;

	// Setters
	void setId(const int id);
	void setDueDate(const time_t dueDate);
	void setIsCompleted(const bool isCompleted);
	void setDescription(const std::string& description);
};
#endif