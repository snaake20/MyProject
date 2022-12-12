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

	Bilet();
	Bilet(const unsigned rand, const unsigned loc, const bool isStandard, Eveniment& eveniment);

	Bilet(Bilet& b);
	~Bilet();

	int createId(Bilet*);

	friend std::istream& operator>> (std::istream& in, Bilet& b);
	friend std::ostream& operator<< (std::ostream& out, const Bilet b);

	//operator!
	Bilet& operator!();
};
