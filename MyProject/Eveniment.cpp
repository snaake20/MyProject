#include "Eveniment.h"
#include "Utils.h"

Eveniment::Eveniment() {
	denumireEveniment = nullptr;
	time = nullptr;
	date = nullptr;
}

Eveniment::Eveniment(const char* denumireEveniment, Time& t, Date& d) {
	Utils::reallocChar(this->denumireEveniment, denumireEveniment);
	this->time = new Time(t);
	this->date = new Date(d);
}

Eveniment::Eveniment(Eveniment& e) {
	Utils::allocChar(this->denumireEveniment, e.denumireEveniment);
	this->time = new Time(*e.time);
	this->date = new Date(*e.date);
}

Eveniment::~Eveniment() {
	Utils::deallocChar(this->denumireEveniment);
	delete time;
	delete date;
}

Eveniment& Eveniment::operator=(Eveniment& e) {
	if (this != &e) {
		Utils::reallocChar(this->denumireEveniment, e.denumireEveniment);
		this->time = new Time(*e.time);
		this->date = new Date(*e.date);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Eveniment e) {
	out << e.denumireEveniment << std::endl;
	out << *e.time << std::endl;
	out << *e.date << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Eveniment& e) {
	std::string buffer;
	std::cout << "Introduceti denumirea evenimentului: ";
	std::getline(in, buffer);
	Utils::reallocChar(e.denumireEveniment, buffer.c_str());
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
