#pragma once
#include <iostream>
#include <string>
#include "Eveniment.h"

class Bilet {
private:
	const int id;
	unsigned sala;
	unsigned rand;
	unsigned loc;
	std::string tipBilet;
	//Eveniment* eveniment;

public:

	Bilet();

	Bilet(const unsigned sala, const unsigned rand, const unsigned loc, const std::string tipBilet ,const char* denumireFilm, const std::string data, const std::string ora);

	Bilet(Bilet& b);

	//~Bilet();

	int createId(Bilet*);

	friend std::istream& operator>> (std::istream& in, Bilet& b);

	friend std::ostream& operator<< (std::ostream& out, const Bilet b);
};
