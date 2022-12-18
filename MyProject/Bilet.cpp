#include "Bilet.h"
#include "Utils.h"

Bilet::Bilet():id(Utils::generateId()) {
	rand = 0;
	loc = 0;
	isStandard = true;
	eveniment = nullptr;
}

Bilet::Bilet(Eveniment& eveniment):id(Utils::generateId())
{
	rand = 0;
	loc = 0;
	isStandard = true;
	this->eveniment = &eveniment;
}

Bilet::Bilet(const unsigned rand, const unsigned loc, const bool isStandard, Eveniment& eveniment):id(Utils::generateId())
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

	unsigned tempRand, tempLoc;
	bool tempIsStandard;
	
	if (b.eveniment->getLocatie().afisareNrLocuriDisponibile() == 0) {
		std::cout << "Nu mai sunt locuri disponibile la acest eveniment!" << std::endl;
		return in;
	}

	b.eveniment->getLocatie().afisareDisponibilitateLocuriSiZone();
	
	
	std::cout << "Nr. locuri standard: " << b.eveniment->getNrLocuriDisponibileStandard() << " nr. locuri speciale: " << b.eveniment->getNrLocuriDisponibileSpeciale() << " total: " << b.eveniment->getLocatie().afisareNrLocuriDisponibile() << std::endl;
	
	std::cout << "Tipul biletului este: (1/0) 1=standard 0=special ";
	in >> tempIsStandard;

	while (in.fail()) {
		in.clear();
		in.ignore(1000, '\n');
		std::cout << "Tipul biletului este gresit. Reintroduceti tipul biletului: (1/0) 1=standard 0=special ";
		in >> tempIsStandard;
	}

	if (!b.eveniment->getNrLocuriDisponibileSpeciale() && tempIsStandard == 0)
	{
		bool raspuns;
		std::cout << "Nu mai exista locuri speciale. Doriti unul standard? (1/0)" << std::endl;
		in >> raspuns;
		if (!raspuns) {
			return in;
		}
		tempIsStandard = true;
	}
	if (!b.eveniment->getNrLocuriDisponibileStandard() && tempIsStandard == 1)
	{
		bool raspuns;
		std::cout << "Nu mai exista locuri standard. Doriti unul special? (1/0)" << std::endl;
		in >> raspuns;
		if (!raspuns) {
			return in;
		}
		tempIsStandard = false;
	}
	
	std::cout << "Nr rand: ";
	in >> tempRand;
	while (tempRand - 1 < 0 || tempRand > b.eveniment->getLocatie().getNrRanduri() ) {
		std::cout << "Randul introdus nu este valid. Introduceti un rand valid: ";
		in >> tempRand;
	}
	
	while (b.eveniment->getLocatie().isRandStandard(tempRand) != tempIsStandard || b.eveniment->getLocatie().getNrLocuriRand(tempRand - 1) == 0) {
		std::cout << "Randul selectat nu este " << (tempIsStandard ? "standard" : "special") << " sau nu mai are locuri disponibile. Introduceti un rand valid: ";
		in >> tempRand;
	}
	
	std::cout << "Loc: ";
	in >> tempLoc;
	while (tempLoc - 1 < 0 || tempLoc > b.eveniment->getLocatie().getNrLocuri()) {
		std::cout << "Locul introdus nu este valid. Introduceti un rand valid: ";
		in >> tempLoc;
	}

	while (b.eveniment->getLocatie()[tempRand - 1][tempLoc - 1] == 0) {
		std::cout << "Locul introdus este ocupat. Introduceti un loc valid: ";
		in >> tempLoc;
	}


	b.rand = tempRand;
	b.loc = tempLoc;
	b.isStandard = tempIsStandard;
	
	b.confirmareBilet();
	
	
	/*std::cout << "Eveniment: ";
	in >> *b.eveniment;*/

	return in;
}

std::ostream& operator<< (std::ostream& out, const Bilet b) {
	out << "Id bilet: " << b.id << std::endl;
	out << "Rand: " << b.rand << std::endl;
	out << "Loc: " << b.loc << std::endl;
	out << "Tipul biletului: " << (b.isStandard == true ? "Standard" : "Special") << std::endl;
	out << *b.eveniment;
	
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

void Bilet::confirmareBilet() {
	this->eveniment->getLocatieToModify()->ocupaLoc(rand - 1, loc - 1);
}

void Bilet::renuntareBilet() {
	this->eveniment->getLocatieToModify()->elibereazaLoc(rand - 1, loc - 1);
}

float Bilet::getPretFinal()
{
	if (this->isStandard)
		return (float)*this->eveniment;
	else return (float)*this->eveniment * 1.5f;
}
