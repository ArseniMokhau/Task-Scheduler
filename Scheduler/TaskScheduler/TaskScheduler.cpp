#include "TaskManager.h"
#include "FileUtils.h"
#include "UserInterface.h"
#include <iostream>
#include <vector>

int main()
{
    std::string filename = "tasks.txt";
    std::string filepath = getUniversalFilePath(filename);

    std::vector<Task> tasks;
    
    loadTaskFromFile(tasks, filepath);
    startUserInterface(tasks);
}