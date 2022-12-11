#pragma once
#include <iostream>
#include <string>
#include "Time.h"
#include "Date.h"

class Eveniment
{
private:
	char* denumireEveniment;
	Time* time;
	Date* date;
public:
	//constructors
	Eveniment();
	Eveniment(const char* denumireEveniment, const Time& t, const Date& d);

	//copy constructor and destructor
	Eveniment(Eveniment& e);
	~Eveniment();

	//operator=
	Eveniment& operator=(Eveniment& e);

	//operator<< and operator>>
	friend std::ostream& operator<<(std::ostream& out, const Eveniment e);
	friend std::istream& operator>>(std::istream& in, Eveniment& e);

	//getters and setters
	char* getDenumireEveniment();
	void setDenumireEveniment();
	Time getTime();
	void setTime(const unsigned day);
	Date getDate();
	void setDate(const unsigned minute);
	

};

