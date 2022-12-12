#include "Locatie.h"
#include "Utils.h"

unsigned Locatie::nrLocatii = 0;

Locatie::Locatie():idLocatie(0)
{
	this->numeLocatie = "";
	this->nrLocuri = 0;
	this->nrRanduri = 0;
	this->disponibilitateLocuri = nullptr;
	nrLocatii++;
}

Locatie::Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri):idLocatie(nrLocatii)
{
	this->numeLocatie = numeLocatie;
	this->nrLocuri = nrLocuri;
	this->nrRanduri = nrRanduri;
	disponibilitateLocuri = new unsigned*[nrRanduri];
	for (int i = 0; i < nrRanduri; i++) {
		disponibilitateLocuri[i] = new unsigned[nrLocuri];
	}
	for (unsigned i = 0; i < nrRanduri; i++)
	{
		for (unsigned j = 0; j < nrLocuri; j++)
		{
			disponibilitateLocuri[i][j] = 1;
		}
	}
	nrLocatii++;
}

Locatie::Locatie(const std::string numeLocatie, const unsigned nrLocuri, const unsigned nrRanduri, const unsigned** disponibilitateLocuri):idLocatie(nrLocatii)
{
	this->numeLocatie = numeLocatie;
	this->nrLocuri = nrLocuri;
	this->nrRanduri = nrRanduri;
	Utils::copy2DArray(this->disponibilitateLocuri, disponibilitateLocuri, nrRanduri, nrLocuri);
	nrLocatii++;
}

Locatie::Locatie(Locatie& l):idLocatie(l.idLocatie)
{
	this->numeLocatie = l.numeLocatie;
	this->nrLocuri = l.nrLocuri;
	this->nrRanduri = l.nrRanduri;
	Utils::alloc2DArray(this->disponibilitateLocuri, l.disponibilitateLocuri, l.nrRanduri, l.nrLocuri);
}

Locatie::~Locatie()
{
	Utils::dealloc2DArray(this->disponibilitateLocuri, this->nrRanduri);
}

std::istream& operator>>(std::istream& in, Locatie& l)
{
	
	
	return in;
}

std::ostream& operator<<(std::ostream& out, const Locatie l)
{
	out << "Locatie: " << l.numeLocatie << std::endl;
	out << "Numar randuri: " << l.nrRanduri << std::endl;
	out << "Numar locuri: " << l.nrLocuri << std::endl;
	out << "Disponibilitate locuri: " << std::endl;
	for (int i = 0; i < l.nrRanduri; i++)
	{
		for (int j = 0; j < l.nrLocuri; j++)
		{
			if (j == 0)
				out << "Rand " << i + 1 << ": ";
			out << (l.disponibilitateLocuri[i][j] == 1 ? "Disponibil" : "Ocupat") << " ";
		}
		out << std::endl;
	}

	return out;
}

//adds a new row
Locatie& Locatie::operator+(const unsigned nrRanduri)
{
	unsigned copyNrRanduri = this->nrRanduri;
	this->nrRanduri += nrRanduri;
	
	unsigned** temp = new unsigned* [copyNrRanduri];
	for (unsigned i = 0; i < copyNrRanduri; i++)
	{
		temp[i] = new unsigned[this->nrLocuri];
		for (unsigned j = 0; j < this->nrLocuri; j++)
		{
			temp[i][j] = disponibilitateLocuri[i][j];
		}
	}

	Utils::dealloc2DArray(this->disponibilitateLocuri, copyNrRanduri);

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

	return *this;
}

//return the row at index
unsigned* Locatie::operator[](const int index)
{
	return this->disponibilitateLocuri[index];
}
