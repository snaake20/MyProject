#pragma once
#include <iostream>
#include <string>

class Locatie
{
private:
	static unsigned nrLocatii;
	const int idLocatie;
	std::string numeLocatie;
	unsigned nrLocuri;
	unsigned nrRanduri;
	unsigned* randuriVip;
	unsigned nrRanduriVip;
	unsigned** disponibilitateLocuri; // to be replaced with a 2d vector of Loc objects
	char** zone; // to be replaced with a 2d vector of Loc objects
public:
	//constructors
	Locatie();
	Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri);
	Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri, const unsigned* randuriVip, const unsigned nrRanduriVip, const unsigned** disponibilitateLocuri, const char** zone);
	
	//copy constructor and destructor
	Locatie(Locatie& l);
	~Locatie();

	//operator=
	Locatie& operator=(const Locatie& l);

	//operator>> and operator<<
	friend std::istream& operator>> (std::istream& in, Locatie& l);
	friend std::ostream& operator<< (std::ostream& out, const Locatie l);

	//operator+
	Locatie& operator+(const unsigned nrRanduri);
	
	//operator[]
	unsigned* operator[](const int index);

	//getters and setters
	std::string getNumeLocatie() const;
	unsigned getNrLocuri() const;
	unsigned getNrRanduri() const;
	unsigned* getRanduriVip() const;
	unsigned getNrRanduriVip() const;
	unsigned** getDisponibilitateLocuri() const;
	char** getZone() const;
	static unsigned getNrLocatii();
	void setNumeLocatie(const std::string numeLocatie);
	void setNrLocuri(const unsigned nrLocuri);
	void setNrRanduri(const unsigned nrRanduri);
	void setRanduriVip(const unsigned* randuriVip, const unsigned nrRanduriVip);
	void setDisponibilitateLocuri(const unsigned** disponibilitateLocuri);
	void setZone(const char** zone);
	static void setNrLocatii(const unsigned nrLocatii);

	//general methods
	void setDefaultDisponibilitate();
	void setDefaultZone();
	void setZonaVip();
	unsigned afisareNrLocuriDisponibile();
	void ocupaLoc(const unsigned rand, const unsigned loc);
	void elibereazaLoc(const unsigned rand, const unsigned loc);
	bool isRandStandard(const unsigned rand);
	unsigned getNrLocuriRand(const unsigned rand);
	
	void afisareDisponibilitateLocuriSiZone();

};