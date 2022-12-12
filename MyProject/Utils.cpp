#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include <ctime>

void Utils::allocChar(char*& dest, const char* src)
{
	if (src != nullptr) {
		dest = new char[strlen(src) + 1];
		strcpy_s(dest, strlen(src) + 1, src);
	}
}

void Utils::reallocChar(char*& dest, const char* src) {
	if (src != nullptr) {
		Utils::deallocChar(dest);
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

void Utils::allocArray(unsigned*& dest, unsigned* src, const unsigned size)
{
	if (size > 0) {
		dest = new unsigned[size];
		for (unsigned i = 0; i < size; i++) {
			dest[i] = src[i];
		}
	}
}

void Utils::alloc2DChar(char**& dest, char** src, const unsigned rows, const unsigned cols)
{
	if (rows > 0 && cols > 0) {
		dest = new char* [rows];
		for (unsigned i = 0; i < rows; i++) {
			dest[i] = new char[cols];
			for (unsigned j = 0; j < cols; j++)
			{
				dest[i][j] = src[i][j];
			}
		}
	}
}

void Utils::copy2DChar(char**& dest, char** src, const unsigned rows, const unsigned cols)
{
	if (rows > 0 && cols > 0) {
		Utils::dealloc2DChar(dest, rows);
		dest = new char* [rows];
		for (unsigned i = 0; i < rows; i++) {
			dest[i] = new char[cols];
			for (unsigned j = 0; j < cols; j++)
			{
				dest[i][j] = src[i][j];
			}
		}
	}
}

void Utils::dealloc2DChar(char**& dest, const unsigned rows)
{
	if (rows > 0) {
		for (unsigned i = 0; i < rows; i++) {
			delete[] dest[i];
		}
		delete[] dest;
		dest = nullptr;
	}
}

void Utils::copyArray(unsigned*& dest, const unsigned* src, const unsigned size)
{
	if (size > 0) {
		Utils::deallocArray(dest);
		dest = new unsigned[size];
		for (unsigned i = 0; i < size; i++) {
			dest[i] = src[i];
		}
	}
}

void Utils::deallocArray(unsigned*& dest)
{
	if (dest != nullptr) {
		delete[] dest;
		dest = nullptr;
	}
}

void Utils::alloc2DArray(unsigned**& dest, unsigned** src, const unsigned rows, const unsigned cols)
{
	if (rows > 0 && cols > 0) {
		dest = new unsigned* [rows];
		for (unsigned i = 0; i < rows; i++) {
			dest[i] = new unsigned[cols];
			for (unsigned j = 0; j < cols; j++) {
				dest[i][j] = src[i][j];
			}
		}
	}
}

void Utils::copy2DArray(unsigned**& dest, const unsigned** src, const unsigned rows, const unsigned cols)
{
	if (rows > 0 && cols > 0) {
		Utils::dealloc2DArray(dest, rows);
		dest = new unsigned* [rows];
		for (unsigned i = 0; i < rows; i++) {
			dest[i] = new unsigned[cols];
			for (unsigned j = 0; j < cols; j++) {
				dest[i][j] = src[i][j];
			}
		}
	}
}

void Utils::dealloc2DArray(unsigned**& dest, const unsigned rows)
{
	if (dest != nullptr) {
		for (unsigned i = 0; i < rows; i++) {
			if (dest[i] != nullptr) {
				delete[] dest[i];
				dest[i] = nullptr;
			}
		}
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
	if (day < now->tm_mday && month == now->tm_mon + 1)
		return false;
	if (month < 1 || month > 12)
		return false;
	if ((month % 2 == 0 && day > 30) || (month % 2 != 0 && day > 31))
		return false;
	if (month == 2 && (!isLeapYear(year) && day > 28) || (isLeapYear(year) && day > 29))
		return false;
	return true;
}

std::tm* Utils::getCurrentDate() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	return now;
}