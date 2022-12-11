#define _CRT_SECURE_NO_WARNINGS
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

void Utils::deallocChar(char*& dest) {
	if (dest != nullptr) {
		delete[] dest;
		dest = nullptr;
	}
}



unsigned Utils::validateHour(const unsigned hour) {
	return (hour >= 0 && hour <= 23) ? hour : 0;
}

unsigned Utils::validateMinute(const unsigned minute) {
	return (minute >= 0 && minute <= 59) ? minute : 0;
}

bool isLeapYear(const unsigned year) {
	if (year % 4 != 0)
		return false;
	if (year % 100 == 0 && year % 400 != 0)
		return false;
	return true;
}

bool Utils::validateDate(const unsigned day, const unsigned month, const unsigned year) {
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t); //tm: struct contains day, month (add 1 since arrays are indexed from 0), year (add 1900 'epoch time')

	if (year < now->tm_year + 1900)
		return false;
	if (month < now->tm_mon + 1 && year == now->tm_year + 1900)
		return false;
	bool leapYear = isLeapYear(year);
	if (day < now->tm_mday && month == now->tm_mon + 1)
		return false;
	if ((month % 2 == 0 && day > 30) || (month % 2 != 0 && day > 31))
		return false;
	if (month == 2 && (!leapYear && day > 28) || (leapYear && day > 29))
		return false;
	return true;
}

std::tm* Utils::getCurrentDate() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	return now;
}