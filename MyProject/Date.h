#pragma once
#include <iostream>
#include <string>

class Date
{
private:
	unsigned day;
	unsigned month;
	unsigned year;

public:
	//constructors
	Date();
	Date(const unsigned day, const unsigned month, const unsigned year);

	//copy constructor and destructor
	Date(Date& d);
	~Date();

	//operator=
	Date& operator=(Date& d);

	//operator<< and operator>>
	friend std::ostream& operator<<(std::ostream& out, const Date d);
	friend std::istream& operator>>(std::istream& in, Date& d);

	//getters and setters
	unsigned getDay();
	void setDay(const unsigned day);
	unsigned getMonth();
	void setMonth(const unsigned minute);
	unsigned getYear();
	void setYear(const unsigned year);

	//general methods
	std::string DateFormatted(const char separator);

};

