#include "Bilet.h"
#include "Utils.h"

Bilet::Bilet():id(0) {
	sala = 0;
	rand = 0;
	loc = 0;
	tipBilet = "";
	
}

Bilet::Bilet(const unsigned sala, const unsigned rand, const unsigned loc, const std::string tipBilet, const char* denumireFilm, const std::string data, const std::string ora):id(createId(this)) {
	this->sala = sala;
	this->rand = rand;
	this->loc = loc;
	this->tipBilet = tipBilet;
	
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
	in >> b.tipBilet;
	std::cout << std::endl;
	std::cout << "Denumire film: ";
	std::string buffer;
	/*in >> buffer;
	if (buffer.length() != 0) {
		Utils::copyChar(b.denumireFilm, buffer.c_str());
	}
	else {
		b.denumireFilm = nullptr;
	}
	std::cout << std::endl;	
	std::cout << "Data film: ";
	in >> b.data;
	std::cout << std::endl;	
	std::cout << "Ora film: ";
	in >> b.ora;
	std::cout << std::endl;*/

	return in;
}

std::ostream& operator<< (std::ostream& out, const Bilet b) {

	out << b.id << std::endl;
	out << b.sala << std::endl;
	out << b.rand << std::endl;
	out << b.loc << std::endl;
	//out << b.film;

	return out;
}