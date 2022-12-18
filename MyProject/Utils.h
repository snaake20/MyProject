#pragma once
#include <iostream>
#include <string>

class Utils
{
public:
	//char related
	static void allocChar(char*& dest, const char* src);
	static void reallocChar(char*& dest, const char* src);
	static void deallocChar(char*& dest);

	//char** related
	static void alloc2DChar(char**& dest, char** src, const unsigned rows, const unsigned cols);
	static void copy2DChar(char**& dest, char** src, const unsigned rows, const unsigned cols);
	static void dealloc2DChar(char**& dest, const unsigned rows);
	
	//dynamic arrays related
	static void allocArray(unsigned*& dest, unsigned* src, const unsigned size);
	static void copyArray(unsigned*& dest, const unsigned* src, const unsigned size);
	static void deallocArray(unsigned*& dest);
	
	//2D dynamic arrays related
	static void alloc2DArray(unsigned**& dest, unsigned** src ,const unsigned rows, const unsigned cols);
	static void copy2DArray(unsigned**& dest, const unsigned** src, const unsigned rows, const unsigned cols);
	static void dealloc2DArray(unsigned**& dest, const unsigned rows);

	//time related
	static unsigned validateHour(const unsigned hour);
	static unsigned validateMinute(const unsigned minute);
	
	//date related
	static bool validateDate(const unsigned day, const unsigned month, const unsigned year);
	static std::tm* getCurrentDate();

	//require imput
	static unsigned requireUnsigned(std::istream& in, const char* message);
	static float requireFloat(std::istream& in, const char* message);
	static std::string requireString(const char* message);
	static std::string generateId();
};

