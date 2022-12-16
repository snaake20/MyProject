#pragma once
#include <iostream>
#include <string>
#include "Locatie.h"
#include "Time.h"
#include "Date.h"

class Eveniment
{
private:
	static unsigned nrEvenimente;
	const unsigned idEveniment;
	char* denumireEveniment;
	float pretBilet;
	Locatie* locatie;
	Time* time;
	Date* date;
public:
	//constructors
	Eveniment();
	Eveniment(const char* denumireEveniment, const float pretBilet, Locatie& l, Time& t, Date& d);

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
	float getPretBilet();
	void setPretBilet(const float pretBilet);
	Time getTime();
	void setTime(const unsigned hour, const unsigned minute);
	Date getDate();
	void setDate(const unsigned day, const unsigned month, const unsigned year);
	Locatie* getLocatie();
	void setLocatie(Locatie& l);
	static unsigned getNrEvenimente();
	static void setNrEvenimente(const unsigned nrEvenimente);

	//general methods
	unsigned getNrLocuriDisponibileStandard();
	unsigned getNrLocuriDisponibileSpeciale();
	
	//preincrement and postincrement -> reprogramare spectacol cu o zi
	Eveniment& operator++();
	Eveniment operator++(int);

	//cast operator to float returns pretBilet
	explicit operator float();

};

