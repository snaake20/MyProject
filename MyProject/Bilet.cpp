#include "Bilet.h"
#include "Utils.h"

Bilet::Bilet():id(0) {
	rand = 0;
	loc = 0;
	isStandard = true;
	eveniment = nullptr;
}

Bilet::Bilet(const unsigned rand, const unsigned loc, const bool isStandard, Eveniment& eveniment): id(createId(this))
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

int Bilet::createId(Bilet*) {
	return (int)this;
}

Bilet::~Bilet()
{
	eveniment = nullptr;
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