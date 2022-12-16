#include "Bilet.h"
#include "Utils.h"

Bilet::Bilet():id(0) {
	rand = 0;
	loc = 0;
	isStandard = true;
	eveniment = nullptr;
}

Bilet::Bilet(const unsigned rand, const unsigned loc, const bool isStandard, Eveniment& eveniment): id(0)
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

bool Bilet::isSeatAvailable(Locatie l, Bilet b)
{
	for (unsigned i = 0; i < l.getNrRanduri(); i++)
	{
		for (unsigned j = 0; j < l.getNrLocuri(); j++)
		{
			if (l[i][j] == 1)
			{
				for (unsigned k = 0; k < l.getNrRanduriVip(); k++)
				{
					if (b.getIsStandard() && i != l.getRanduriVip()[k])
						return true;
					else return false;
					if (!b.getIsStandard() && i == l.getRanduriVip()[k])
						return true;
					else return false;
				}
			}
		}
	}
}

void Bilet::ocupaLoc(Locatie l, Bilet b)
{
	for (unsigned i = 0; i < l.getNrRanduri(); i++)
	{
		for (unsigned j = 0; j < l.getNrLocuri(); j++)
		{
			if (l[i][j] == 1)
			{
				for (unsigned k = 0; k < l.getNrRanduriVip(); k++)
				{
					if (b.getIsStandard() && i != l.getRanduriVip()[k])
						l[i][j] = 0;
					if (!b.getIsStandard() && i == l.getRanduriVip()[k])
						l[i][j] = 0;
				}
			}
		}
	}
}

void Bilet::elibereazaLoc(Locatie l, Bilet b)
{
	for (unsigned i = 0; i < l.getNrRanduri(); i++)
	{
		for (unsigned j = 0; j < l.getNrLocuri(); j++)
		{
			if (l[i][j] == 0)
			{
				for (unsigned k = 0; k < l.getNrRanduriVip(); k++)
				{
					if (b.getIsStandard() && i != l.getRanduriVip()[k])
						l[i][j] = 1;
					if (!b.getIsStandard() && i == l.getRanduriVip()[k])
						l[i][j] = 1;
				}
			}
		}
	}
}

float Bilet::getPretFinal()
{
	if (this->isStandard)
		return this->eveniment->getPretBilet();
	else return this->eveniment->getPretBilet() * 1.5;
}
