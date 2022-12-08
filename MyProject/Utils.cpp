#include <iostream>
#include "Utils.h"

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