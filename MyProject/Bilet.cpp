#include "Bilet.h"
#include "Utils.h"

Bilet::Bilet():id(0) {
	sala = 0;
	rand = 0;
	loc = 0;
	
}

Bilet::Bilet(const unsigned sala, const unsigned rand, const unsigned loc, const bool isSpecialTicket): id(createId(this))
{
	this->sala = sala;
	this->rand = rand;
	this->loc = loc;
}

Bilet::Bilet(Bilet&b):id(b.id) {
	this->sala = b.sala;
	this->rand = b.rand;
	this->loc = b.loc;

}

int Bilet::createId(Bilet*) {
	return (int)this;
}

std::istream& operator>> (std::istream& in, Bilet& b) {
	std::cout << "Nr sala: ";
	in >> b.sala;
	std::cout << std::endl;
	std::cout << "Nr rand: ";
	in >> b.rand;
	std::cout << std::endl;
	std::cout << "Loc: ";
	in >> b.loc;
	std::cout << std::endl;
	std::cout << "Tip bilet: ";

	return in;
}

std::ostream& operator<< (std::ostream& out, const Bilet b) {

	out << b.id << std::endl;
	out << b.sala << std::endl;
	out << b.rand << std::endl;
	out << b.loc << std::endl;
	//out << b.eveniment;

	return out;
}