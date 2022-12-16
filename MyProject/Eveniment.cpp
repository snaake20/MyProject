#include "Eveniment.h"
#include "Utils.h"

unsigned Eveniment::nrEvenimente = 1;

Eveniment::Eveniment():idEveniment(nrEvenimente) {
	denumireEveniment = nullptr;
	pretBilet = 0.f;
	locatie = nullptr;
	time = nullptr;
	date = nullptr;
}

Eveniment::Eveniment(const char* denumireEveniment, const float pretBilet, Locatie& l, Time& t, Date& d):idEveniment(nrEvenimente) {
	Utils::reallocChar(this->denumireEveniment, denumireEveniment);
	this->pretBilet = pretBilet;
	this->locatie = &l;
	this->time = new Time(t);
	this->date = new Date(d);
}

Eveniment::Eveniment(Eveniment& e):idEveniment(e.idEveniment) {
	Utils::allocChar(this->denumireEveniment, e.denumireEveniment);
	this->pretBilet = e.pretBilet;
	this->locatie = e.locatie;
	this->time = new Time(*e.time);
	this->date = new Date(*e.date);
}

Eveniment::~Eveniment() {
	Utils::deallocChar(this->denumireEveniment);
	locatie = nullptr;
	delete time;
	delete date;
}

Eveniment& Eveniment::operator=(Eveniment& e) {
	if (this != &e) {
		Utils::reallocChar(this->denumireEveniment, e.denumireEveniment);
		this->pretBilet = e.pretBilet;
		this->locatie = e.locatie;
		this->time = new Time(*e.time);
		this->date = new Date(*e.date);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Eveniment e) {
	out << e.denumireEveniment << std::endl;
	out << e.pretBilet << std::endl;
	out << *e.locatie << std::endl;
	out << *e.time << std::endl;
	out << *e.date << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Eveniment& e) {
	std::string buffer;
	std::cout << "Introduceti denumirea evenimentului: ";
	buffer = Utils::requireString("Denumirea evenimentului nu poate fi vida! Reintroduceti denumirea evenimentului: ");
	Utils::reallocChar(e.denumireEveniment, buffer.c_str());
	std::cout << "Introduceti pretul biletului: ";
	e.pretBilet = Utils::requireFloat("Pretul biletului trebuie sa fie un numar pozitiv! Reintroduceti pretul biletului: ");
	in >> *e.locatie;
	in >> *e.time;
	in >> *e.date;
	return in;
}

char* Eveniment::getDenumireEveniment() {
	char* copy = nullptr;
	Utils::allocChar(copy, this->denumireEveniment);
	return copy;
}

void Eveniment::setDenumireEveniment(const char* denumireEveniment) {
	Utils::reallocChar(this->denumireEveniment, denumireEveniment);
}

float Eveniment::getPretBilet()
{
	return this->pretBilet;
}

void Eveniment::setPretBilet(const float pretBilet)
{
	if (pretBilet > 0.f) {
		this->pretBilet = pretBilet;
	}
}

Time Eveniment::getTime() {
	Time copy(*this->time);
	return copy;
}

void Eveniment::setTime(const unsigned hour, const unsigned minute) {
	this->time->setHour(hour);
	this->time->setMinute(minute);
}

Date Eveniment::getDate() {
	Date copy(*this->date);
	return copy;
}

void Eveniment::setDate(const unsigned day, const unsigned month, const unsigned year) {
	this->date->setDay(day);
	this->date->setMonth(month);
	this->date->setYear(year);
}

Locatie* Eveniment::getLocatie()
{
	return this->locatie;
}

void Eveniment::setLocatie(Locatie& l)
{
	if (&l != nullptr) 
		this->locatie = &l;
}

Eveniment& Eveniment::operator++()
{
	this->date->setDay(this->date->getDay() + 1);
	return *this;
}

Eveniment Eveniment::operator++(int)
{
	Eveniment copy = *this;
	this->date->setDay(this->date->getDay() + 1);
	return copy;
}

Eveniment::operator float()
{
	return this->pretBilet;
}
