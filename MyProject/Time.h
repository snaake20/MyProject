#pragma once
#include <iostream>
#include <string>

//simple class for 24h format time
class Time
{
private:
	unsigned hour;
	unsigned minute;
public:
	//constructors
	Time();
	Time(unsigned hour, unsigned minute);

	//copy constructor and destructor
	Time(Time& t);
	~Time();

	//operator=
	Time& operator=(Time& t);

	//operator<< and operator>>
	friend std::ostream& operator<<(std::ostream& out, const Time t);
	friend std::istream& operator>>(std::istream& in, Time& t);

	//getters and setters
	unsigned getHour();
	void setHour(const unsigned hour);
	unsigned getMinute();
	void setMinute(const unsigned minute);

	//general methods
	std::string timeFormatted(const char separator);

};

