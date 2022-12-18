#include "Locatie.h"
#include "Utils.h"

unsigned Locatie::nrLocatii = 1;

Locatie::Locatie():idLocatie(nrLocatii)
{
	this->numeLocatie = "";
	this->nrLocuri = 0;
	this->nrRanduri = 0;
	this->randuriVip = nullptr;
	this->nrRanduriVip = 0;
	this->disponibilitateLocuri = nullptr;
	this->zone = nullptr;
	nrLocatii++;
}

Locatie::Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri):idLocatie(nrLocatii)
{
	this->numeLocatie = numeLocatie;
	this->nrLocuri = nrLocuri;
	this->nrRanduri = nrRanduri;
	this->randuriVip = nullptr;
	this->nrRanduriVip = 0;
	disponibilitateLocuri = new unsigned*[nrRanduri];
	for (unsigned i = 0; i < nrRanduri; i++) {
		disponibilitateLocuri[i] = new unsigned[nrLocuri];
	}
	for (unsigned i = 0; i < nrRanduri; i++)
	{
		for (unsigned j = 0; j < nrLocuri; j++)
		{
			disponibilitateLocuri[i][j] = 1;
		}
	}
	zone = new char* [nrRanduri];
	for (unsigned i = 0; i < nrRanduri; i++) {
		zone[i] = new char[nrLocuri];
	}
	for (unsigned i = 0; i < nrRanduri; i++)
	{
		for (unsigned j = 0; j < nrLocuri; j++)
		{
			if (nrRanduri % 2 == 0) {
				if (i < nrRanduri / 2) {
					zone[i][j] = '1';
				}
				if (i >= nrRanduri / 2) {
					zone[i][j] = '2';
				}
			}
			else {
				if (i < nrRanduri / 2) {
					zone[i][j] = '1';
				}
				if (i > nrRanduri / 2) {
					zone[i][j] = '2';
				}
				if (i == nrRanduri / 2) {
					zone[i][j] = '3';
				}
			}
		}
	}
	nrLocatii++;
}

Locatie::Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri, const unsigned* randuriVip, const unsigned nrRanduriVip, const unsigned** disponibilitateLocuri, const char** zone):idLocatie(nrLocatii)
{
	this->numeLocatie = numeLocatie;
	this->nrLocuri = nrLocuri;
	this->nrRanduri = nrRanduri;
	this->nrRanduriVip = nrRanduriVip;
	Utils::copyArray(this->randuriVip, randuriVip , nrRanduriVip);
	Utils::copy2DArray(this->disponibilitateLocuri, disponibilitateLocuri, nrRanduri, nrLocuri);
	Utils::copy2DChar(this->zone, (char**)zone, nrRanduri, nrLocuri);
	nrLocatii++;
}

Locatie::Locatie(Locatie& l):idLocatie(l.idLocatie)
{
	this->numeLocatie = l.numeLocatie;
	this->nrLocuri = l.nrLocuri;
	this->nrRanduri = l.nrRanduri;
	this->nrRanduriVip = l.nrRanduriVip;
	Utils::allocArray(this->randuriVip, l.randuriVip, l.nrRanduriVip);
	Utils::alloc2DArray(this->disponibilitateLocuri, l.disponibilitateLocuri, l.nrRanduri, l.nrLocuri);
	Utils::alloc2DChar(this->zone, l.zone, l.nrRanduri, l.nrLocuri);
}

Locatie::~Locatie()
{
	Utils::deallocArray(this->randuriVip);
	Utils::dealloc2DArray(this->disponibilitateLocuri, this->nrRanduri);
	Utils::dealloc2DChar(this->zone, this->nrRanduri);
}

Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l) {
		this->numeLocatie = l.numeLocatie;
		this->nrLocuri = l.nrLocuri;
		this->nrRanduri = l.nrRanduri;
		this->nrRanduriVip = l.nrRanduriVip;
		Utils::copyArray(this->randuriVip, l.randuriVip, nrRanduri);
		Utils::copy2DArray(this->disponibilitateLocuri, (const unsigned**)l.disponibilitateLocuri, l.nrRanduri, l.nrLocuri);
		Utils::copy2DChar(this->zone, l.zone, l.nrRanduri, l.nrLocuri);
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Locatie& l)
{
	std::cout << "Nume locatie: ";
	l.numeLocatie = Utils::requireString("Ai introdus un string invalid. Introdu iar numele locatiei: ");
	std::cout << "Numar randuri: ";
	l.nrRanduri = Utils::requireUnsigned(in, "Ai introdus un numar invalid. Introdu iar numarul de randuri: ");
	std::cout << "Numar locuri: ";
	l.nrLocuri = Utils::requireUnsigned(in, "Ai introdus un numar invalid. Introdu iar numarul de locuri (pe rand): ");
	std::cout << "Numar randuri VIP: ";
	l.nrRanduriVip = Utils::requireUnsigned(in, "Ai introdus un numar invalid. Introdu iar numarul de randuri VIP: ");
	while (l.nrRanduriVip > l.nrRanduri) {
		std::cout << "Numarul de randuri VIP nu poate fi mai mare decat numarul de randuri. Introdu iar numarul de randuri VIP: ";
		l.nrRanduriVip = Utils::requireUnsigned(in, "Ai introdus un numar invalid. Introdu iar numarul de randuri VIP: ");
	}
	if (l.nrRanduriVip > 0) {
		l.randuriVip = new unsigned[l.nrRanduriVip];
		for (unsigned i = 0; i < l.nrRanduriVip; i++)
		{
			unsigned temp;
			std::cout << "Randurile vip sunt: ";
			in >> temp;
			while (temp - 1 < 0 || temp - 1 > l.nrRanduri) {
				std::cout << "Randul introdus nu exista. Introdu iar randul: ";
				in >> temp;
			}
			l.randuriVip[i] = temp;
		}
	}
	else {
		l.randuriVip = nullptr;
	}
	
	l.setDefaultDisponibilitate();
	l.setDefaultZone();
	if (l.randuriVip && l.nrRanduriVip > 0)
		l.setZonaVip();

	return in;
}

std::ostream& operator<<(std::ostream& out, const Locatie l)
{
	if (l.numeLocatie.empty()) {
		out << "Eveniment nedenumit" << std::endl;
	}
	else {
		out << "Locatie: " << l.numeLocatie << std::endl;
	}
	if (l.nrRanduri < 1 || l.nrLocatii < 1) {
		out << "Nu exista randuri sau locuri, locuri disponibile sau zone" << std::endl;
	}
	else {
		out << "Numar randuri: " << l.nrRanduri << std::endl;
		out << "Numar locuri: " << l.nrLocuri << std::endl;
		out << "Disponibilitate locuri: " << std::endl;
		for (unsigned i = 0; i < l.nrRanduri; i++)
		{
			for (unsigned j = 0; j < l.nrLocuri; j++)
			{
				out << l.disponibilitateLocuri[i][j] << " ";
			}
			out << std::endl;
		}
		out << "Zone: " << std::endl;
		for (unsigned i = 0; i < l.nrRanduri; i++)
		{
			for (unsigned j = 0; j < l.nrLocuri; j++)
			{
				out << l.zone[i][j] << " ";
			}
			out << std::endl;
		}
	}

	return out;
}

//adds a/multiple new row/s
Locatie& Locatie::operator+(const unsigned nrRanduri)
{
	unsigned copyNrRanduri = this->nrRanduri;
	this->nrRanduri += nrRanduri;
	
	unsigned** temp = nullptr;
	Utils::alloc2DArray(temp, this->disponibilitateLocuri, copyNrRanduri, this->nrLocuri);

	Utils::dealloc2DArray(this->disponibilitateLocuri, copyNrRanduri);
	Utils::dealloc2DChar(this->zone, copyNrRanduri);

	this->disponibilitateLocuri = new unsigned* [this->nrRanduri];
	for (unsigned i = 0; i < this->nrRanduri; i++)
	{
		this->disponibilitateLocuri[i] = new unsigned[this->nrLocuri];
		for (unsigned j = 0; j < this->nrLocuri; j++)
		{
			if (i < copyNrRanduri)
				this->disponibilitateLocuri[i][j] = temp[i][j];
			this->disponibilitateLocuri[i][j] = 1;
		}
		
	}
	
	Utils::dealloc2DArray(temp, copyNrRanduri);

	this->zone = new char* [this->nrRanduri];
	for (unsigned i = 0; i < this->nrRanduri; i++)
	{
		this->zone[i] = new char[this->nrLocuri];
		for (unsigned j = 0; j < this->nrLocuri; j++)
		{
			if (nrRanduri % 2 == 0) {
				if (i < this->nrRanduri / 2) {
					zone[i][j] = '1';
				}
				if (i >= this->nrRanduri / 2) {
					zone[i][j] = '2';
				}
			}
			else {
				if (i < this->nrRanduri / 2) {
					zone[i][j] = '1';
				}
				if (i == this->nrRanduri / 2) {
					zone[i][j] = '3';
				}
				if (i >= this->nrRanduri / 2) {
					zone[i][j] = '2';
				}
			}
		}
	}

	if (this->randuriVip && this->nrRanduriVip > 0)
		setZonaVip();

	return *this;
}

//return the row at index
unsigned* Locatie::operator[](const unsigned index)
{
	if (this->disponibilitateLocuri == nullptr) {
		std::cout << "Disponibilitatea locatiei nu a fost stabilita" << std::endl;
		return nullptr;
	}
	if (index < 0 || index > this->nrRanduri) {
		std::cout << "Index invalid" << std::endl;
		return nullptr;
	}
	return this->disponibilitateLocuri[index];
}

std::string Locatie::getNumeLocatie() const
{
	return this->numeLocatie;
}

unsigned Locatie::getNrLocuri() const
{
	return this->nrLocuri;
}

unsigned Locatie::getNrRanduri() const
{
	return this->nrRanduri;
}

unsigned* Locatie::getRanduriVip() const
{
	unsigned* temp = nullptr;
	Utils::copyArray(temp, this->randuriVip, this->nrRanduriVip);
	return temp;
}

unsigned Locatie::getNrRanduriVip() const
{
	return this->nrRanduriVip;
}

unsigned** Locatie::getDisponibilitateLocuri() const
{
	unsigned** temp = nullptr;
	Utils::alloc2DArray(temp, this->disponibilitateLocuri, this->nrRanduri, this->nrLocuri);
	return temp;
}

char** Locatie::getZone() const
{
	char** temp = nullptr;
	Utils::alloc2DChar(temp, this->zone, this->nrRanduri, this->nrLocuri);
	return temp;
}

unsigned Locatie::getNrLocatii()
{
	return Locatie::nrLocatii;
}

void Locatie::setNumeLocatie(const std::string numeLocatie)
{
	if (!numeLocatie.empty())
		this->numeLocatie = numeLocatie;
}

void Locatie::setNrLocuri(const unsigned nrLocuri)
{
	if (nrLocuri > 0)
		this->nrLocuri = nrLocuri;
}

void Locatie::setNrRanduri(const unsigned nrRanduri)
{
	if (nrRanduri > 0)
		this->nrRanduri = nrRanduri;
}

void Locatie::setRanduriVip(const unsigned* randuriVip, const unsigned nrRanduriVip)
{
	if (randuriVip != nullptr && nrRanduriVip > 0) {
		this->nrRanduriVip = nrRanduriVip;
		if (this->randuriVip != nullptr)
			delete[] this->randuriVip;
		this->randuriVip = new unsigned[this->nrRanduriVip];
		for (unsigned i = 0; i < this->nrRanduriVip; i++)
			this->randuriVip[i] = randuriVip[i];
		this->setZonaVip();
	}
}

void Locatie::setDisponibilitateLocuri(const unsigned** disponibilitateLocuri)
{
	if (disponibilitateLocuri != nullptr && nrRanduri > 0 && nrLocuri > 0)
		Utils::copy2DArray(this->disponibilitateLocuri, disponibilitateLocuri, this->nrRanduri, this->nrLocuri);
}

void Locatie::setZone(const char** zone)
{
	if (zone != nullptr && nrRanduri > 0 && nrLocuri > 0)
		Utils::copy2DChar(this->zone, (char**)zone, this->nrRanduri, this->nrLocuri);
}

void Locatie::setNrLocatii(const unsigned nrLocatii)
{
	if (nrLocatii > 0)
		Locatie::nrLocatii = nrLocatii;
}

void Locatie::setDefaultDisponibilitate()
{
	disponibilitateLocuri = new unsigned* [nrRanduri];
	for (unsigned i = 0; i < nrRanduri; i++) {
		disponibilitateLocuri[i] = new unsigned[nrLocuri];
	}
	for (unsigned i = 0; i < nrRanduri; i++)
	{
		for (unsigned j = 0; j < nrLocuri; j++)
		{
			disponibilitateLocuri[i][j] = 1;
		}
	}
}

void Locatie::setDefaultZone()
{
	zone = new char* [nrRanduri];
	for (unsigned i = 0; i < nrRanduri; i++) {
		zone[i] = new char[nrLocuri];
	}
	if (nrRanduri % 2 == 1) {	
		for (unsigned i = 0; i < nrRanduri; i++)
		{
			for (unsigned j = 0; j < nrLocuri; j++)
			{
				if (i < nrRanduri / 2) {
					zone[i][j] = '1';
				}
				if (i == nrRanduri / 2) {
					zone[i][j] = '3';
				}
				if (i > nrRanduri / 2) {
					zone[i][j] = '2';
				}
			}
		}
	}
	if (nrRanduri % 2 == 0) {
		for (unsigned i = 0; i < nrRanduri; i++)
		{
			for (unsigned j = 0; j < nrLocuri; j++)
			{
				if (i < nrRanduri / 2) {
					zone[i][j] = '1';
				}
				if (i > nrRanduri / 2) {
					zone[i][j] = '2';
				}
			}
		}
	}
}

void Locatie::setZonaVip()
{
	if (this->randuriVip == nullptr || this->nrRanduriVip == 0) {
		std::cout << "Nu ati specificat randurile VIP pentru aceasta locatie" << std::endl;
		return;
	}
	for (unsigned i = 0; i < nrRanduriVip; i++)
	{
		for (unsigned j = 0; j < nrLocuri; j++)
		{
			zone[randuriVip[i] - 1][j] = 'S';
		}
	}
}

unsigned Locatie::afisareNrLocuriDisponibile()
{
	unsigned acc = 0;
	for (unsigned i = 0; i < nrRanduri; i++)
	{
		for (unsigned j = 0; j < nrLocuri; j++)
		{
			if (disponibilitateLocuri[i][j] == 1)
				acc++;
		}
	}
	return acc;
}

void Locatie::ocupaLoc(const unsigned rand, const unsigned loc)
{
	this->disponibilitateLocuri[rand][loc] = 0;
}

void Locatie::elibereazaLoc(const unsigned rand, const unsigned loc)
{
	this->disponibilitateLocuri[rand][loc] = 1;
}

bool Locatie::isRandStandard(const unsigned rand)
{
	for (unsigned i = 0; i < this->nrRanduriVip; i++)
	{
		if (rand == this->randuriVip[i])
			return false;
	}
	return true;
}

unsigned Locatie::getNrLocuriRand(const unsigned rand)
{
	unsigned acc = 0;
	for (unsigned i = 0; i < this->nrLocuri; i++)
	{
		if (this->disponibilitateLocuri[rand][i] == 1)
			acc++;
	}
	return acc;
}

void Locatie::afisareDisponibilitateLocuriSiZone() {
	std::cout << "Disponibilitate locuri: " << std::endl;
	for (unsigned i = 0; i < this->nrRanduri; i++)
	{
		for (unsigned j = 0; j < this->nrLocuri; j++)
		{
			std::cout << this->disponibilitateLocuri[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Zone: " << std::endl;
	for (unsigned i = 0; i < this->nrRanduri; i++)
	{
		for (unsigned j = 0; j < this->nrLocuri; j++)
		{
			std::cout << this->zone[i][j] << " ";
		}
		std::cout << std::endl;
	}
}