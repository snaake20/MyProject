#include "Utils.h"
#include <ctime>

void Utils::copyChar(char*& dest, const char* src) {
	if (src != nullptr) {
		if (dest != nullptr) {
			delete[] dest;
		}
		dest = new char[strlen(src) + 1];
		strcpy_s(dest, strlen(src) + 1, src);
	}
}

unsigned Utils::validateHour(const unsigned hour) {
	return (hour >= 0 && hour <= 23) ? hour : 0;
}

unsigned Utils::validateMinute(const unsigned minute) {
	return (minute >= 0 && minute <= 59) ? minute : 0;
}

bool Utils::validateDate(const unsigned day, const unsigned month, const unsigned year) {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t); //tm: struct contains day, month (add 1 since arrays are indexed from 0), year (add 1900 'epoch time')
	if (year < now->tm_year + 1900)
		return false;
	if (month < now->tm_mon + 1)
		return false;
	if (day < now->tm_mday && month == now->tm_mon + 1)
		return false;
	return true;
}