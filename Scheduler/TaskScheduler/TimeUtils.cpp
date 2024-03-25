#include "TimeUtils.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <regex>

time_t convertStringToTimeT(const std::string& dateTimeString) {
	std::tm tm = {};
	std::istringstream ss(dateTimeString);
	ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");

	if (ss.fail()) {
		throw std::runtime_error("Failed to parse date and time string.");
	}

	time_t time = std::mktime(&tm);
	if (time == -1) {
		throw std::runtime_error("Failed to convert date and time to time_t.");
	}

	return time;
}

std::string convertTimeTToString(time_t time) {
	std::tm localTime;
	localtime_s(&localTime, &time); // Convert time_t to struct tm

	char buffer[80]; // Buffer for the formatted string
	if (strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime) == 0) {
		throw std::runtime_error("Failed to format time.");
	}

	return std::string(buffer);
}

bool validateDateTimeFormat(const std::string& dateTimeString) {
    // Define the regex pattern for date and time format "YYYY-MM-DD HH:MM"
    std::regex pattern("\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}");

    // Check if the input string matches the regex pattern
    if (!std::regex_match(dateTimeString, pattern)) {
        return false;
    }

    // Parse year, month, day, hour, and minute from the input string
    int year, month, day, hour, minute;
    if (sscanf_s(dateTimeString.c_str(), "%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute) != 5) {
        return false;
    }

    // Check if year, month, and day are within valid ranges
    if (year < 1900 || year > 3000 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Check if hour and minute are within valid ranges
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return false;
    }

    // Check if the date is valid (February 30 is not a valid date)
    if (day > 28 && month == 2) {
        int daysInFebruary = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        if (day > daysInFebruary) {
            return false;
        }
    }

    return true;
}