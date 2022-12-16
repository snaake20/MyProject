#pragma once
#include <iostream>
#include <string>
#include "Eveniment.h"

class Bilet {
private:
	const int id;
	unsigned rand;
	unsigned loc;
	bool isStandard;
	Eveniment* eveniment;

public:
	//constructors
	Bilet();
	Bilet(const unsigned rand, const unsigned loc, const bool isStandard, Eveniment& eveniment);

	//copy constructor and destructor
	Bilet(Bilet& b);
	~Bilet();

	//operator=
	Bilet& operator=(const Bilet& b);

	//operator>> and operator<<
	friend std::istream& operator>> (std::istream& in, Bilet& b);
	friend std::ostream& operator<< (std::ostream& out, const Bilet b);

	//operator!
	Bilet& operator!();

	//operator== doua bilete au acelasi eveniment, locatie
	bool operator==(const Bilet& b);

	//getters and setters
	unsigned getRand();
	void setRand(const unsigned rand);
	unsigned getLoc();
	void setLoc(const unsigned loc);
	bool getIsStandard();
	void setIsStandard(const bool isStandard);
	Eveniment* getEveniment();
	void setEveniment(Eveniment& eveniment);
	
	//generalMethods
	float getPretFinal();
	void ocupaLoc(Locatie l, Bilet b);
	void elibereazaLoc(Locatie l, Bilet b);
	static bool isSeatAvailable(Locatie l, Bilet b);

};
