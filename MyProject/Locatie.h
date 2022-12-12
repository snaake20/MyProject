#pragma once
#include <iostream>

class Locatie
{
private:
	static unsigned nrLocatii;
	const int idLocatie;
	std::string numeLocatie;
	unsigned nrLocuri;
	unsigned nrRanduri;
	unsigned** disponibilitateLocuri;
public:
	//constructors
	Locatie();
	Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri);
	Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri, const unsigned** disponibilitateLocuri);
	
	//copy constructor and destructor
	Locatie(Locatie& l);
	~Locatie();

	//operator>> and operator<<
	friend std::istream& operator>> (std::istream& in, Locatie& l);
	friend std::ostream& operator<< (std::ostream& out, const Locatie l);

	//operator+
	Locatie& operator+(const unsigned nrRanduri);
	
	//operator[]
	unsigned* operator[](const int index);

};

