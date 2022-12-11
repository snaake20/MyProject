#pragma once
#include <iostream>

class Utils
{
public:
	static void allocChar(char*& dest, const char* src);
	static void reallocChar(char*& dest, const char* src);
	static void deallocChar(char*& dest);
	static unsigned validateHour(const unsigned hour);
	static unsigned validateMinute(const unsigned minute);
	static bool validateDate(const unsigned day, const unsigned month, const unsigned year);
	static std::tm* getCurrentDate();
};

