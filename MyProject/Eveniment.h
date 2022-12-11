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
	Eveniment(const char* denumireEveniment, Time& t, Date& d);

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
	void setDenumireEveniment(const char* denumireEveniment);
	Time getTime();
	void setTime(const unsigned hour, const unsigned minute);
	Date getDate();
	void setDate(const unsigned day, const unsigned month, const unsigned year);
	
	//preincrement and postincrement
	Eveniment& operator++(); //reprogramare spectacol
	Eveniment operator++(int); //reprogramare spectacol

};

