#include "Bilet.h"
#include "Utils.h"

Bilet::Bilet():id(CiD::generateCiD()) {
	rand = 0;
	loc = 0;
	isStandard = true;
	eveniment = nullptr;
}

Bilet::Bilet(const unsigned rand, const unsigned loc, const bool isStandard, Eveniment& eveniment): id(CiD::generateCiD())
{
	this->rand = rand;
	this->loc = loc;
	this->isStandard = isStandard;
	this->eveniment = &eveniment;
}

Bilet::Bilet(Bilet&b):id(b.id) {
	this->rand = b.rand;
	this->loc = b.loc;
	this->isStandard = b.isStandard;
	this->eveniment = b.eveniment;
}

Bilet::~Bilet()
{
	eveniment = nullptr;
}

Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b) {
		this->rand = b.rand;
		this->loc = b.loc;
		this->isStandard = b.isStandard;
		this->eveniment = b.eveniment;
	}
	return *this;
}

std::istream& operator>> (std::istream& in, Bilet& b) {
	std::cout << "Nr rand: ";
	in >> b.rand;
	std::cout << "Loc: ";
	in >> b.loc;
	std::cout << "Biletul este standard: (1/0) ";
	in >> b.isStandard;
	std::cout << "Eveniment: ";
	in >> *b.eveniment;

	return in;
}

std::ostream& operator<< (std::ostream& out, const Bilet b) {

	out << "Id bilet: " << b.id << std::endl;
	out << "Rand: " << b.rand << std::endl;
	out << "Loc: " << b.loc << std::endl;
	out << "Tipul biletului: " << (b.isStandard == true ? "Standard" : "Special") << std::endl;
	out << "Eveniment: " << *b.eveniment;
	
	return out;
}

Bilet& Bilet::operator!() {
	this->isStandard = !this->isStandard;
	return *this;
}

unsigned Bilet::getRand()
{
	return this->rand;
}

bool Bilet::operator==(const Bilet& b)
{
	return this->id == b.id;
}

void Bilet::setRand(const unsigned rand)
{
	this->rand = rand;
}

unsigned Bilet::getLoc()
{
	return this->loc;
}

void Bilet::setLoc(const unsigned loc)
{
	this->loc = loc;
}

bool Bilet::getIsStandard()
{
	return this->isStandard;
}

void Bilet::setIsStandard(const bool isStandard)
{
	this->isStandard = isStandard;
}

Eveniment* Bilet::getEveniment()
{
	return this->eveniment;
}

void Bilet::setEveniment(Eveniment& eveniment)
{
	if (&eveniment != nullptr) 
		this->eveniment = &eveniment;
}

void Bilet::ocupaLoc(Locatie l)
{
	if (l[this->rand][this->loc] == 1)
	{
		for (unsigned k = 0; k < l.getNrRanduriVip(); k++)
		{
			if (this->isStandard && this->rand != l.getRanduriVip()[k])
				l[this->rand][this->loc] = 0;
			if (!this->isStandard && this->rand == l.getRanduriVip()[k])
				l[this->rand][this->loc] = 0;
		}
	}
}

void Bilet::elibereazaLoc(Locatie l)
{
	l[this->rand][this->loc] = 1;
}

float Bilet::getPretFinal()
{
	if (this->isStandard)
		return (float)*this->eveniment;
	else return (float)*this->eveniment * 1.5f;
}
