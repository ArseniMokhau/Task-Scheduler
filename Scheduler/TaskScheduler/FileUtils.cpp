#include "FileUtils.h"
#include <filesystem>
#include <string>
#include <cstdlib>

std::string getUniversalFilePath(const std::string& filename) {
    // Get the directory separator for the current platform
    char separator = std::filesystem::path::preferred_separator;

    std::string directoryPath;
#ifdef _WIN32 // Windows
    char* userProfile;
    size_t requiredSize;
    if (_dupenv_s(&userProfile, &requiredSize, "USERPROFILE") == 0 && userProfile != nullptr) {
        directoryPath = userProfile;
        free(userProfile);
    }
    else {
        directoryPath = "C:\\Users\\Default";
    }
#else // Unix-like systems (Linux, macOS)
    char* homeDir;
    size_t requiredSize;
    if (_dupenv_s(&homeDir, &requiredSize, "HOME") == 0 && homeDir != nullptr) {
        directoryPath = homeDir;
        free(homeDir);
    }
    else {
        directoryPath = "/home/default";
    }
#endif

    // Append the file name to the directory path
    std::filesystem::path filePath = directoryPath + separator + filename;

    return filePath.string();
}
