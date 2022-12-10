#pragma once
#include <iostream>

class Utils
{
public:
	static void copyChar(char*& dest, const char* src);
	static unsigned validateHour(const unsigned hour);
	static unsigned validateMinute(const unsigned minute);
	static bool validateDate(const unsigned day, const unsigned month, const unsigned year);
};

