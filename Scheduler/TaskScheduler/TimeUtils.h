#ifndef TIME_UTILS_H

#define TIME_UTILS_H

#include <string>
#include <ctime>

time_t convertStringToTimeT(const std::string& dateTimeString);

std::string convertTimeTToString(time_t time);

bool validateDateTimeFormat(const std::string& dateTimeString);

#endif // !TIME_UTILS_H

