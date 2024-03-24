#include "Task.h"

Task::Task(int id, const std::string& description, time_t dueDate) \
	: id(id), description(description), dueDate(dueDate), isCompleted(false) {}


int Task::getId() const
{
	return id;
}

time_t Task::getDueDate() const
{
	return dueDate;
}

bool Task::getIsComplited() const
{
	return isCompleted;
}

std::string Task::getDescription() const
{
	return description;
}

void Task::setId(const int id)
{
	this->id = id;
}

void Task::setDueDate(const time_t dueDate)
{
	this->dueDate = dueDate;
}

void Task::setIsCompleted(const bool isCompleted)
{
	this->isCompleted = isCompleted;
}

void Task::setDescription(const std::string& description)
{
	this->description = description;
}

