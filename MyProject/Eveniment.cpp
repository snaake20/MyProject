#include "Eveniment.h"
#include "Utils.h"

Eveniment::Eveniment() {
	denumireEveniment = nullptr;
	time = nullptr;
	date = nullptr;
}

Eveniment::Eveniment(const char* denumireEveniment, Time& t, Date& d) {
	Utils::copyChar(this->denumireEveniment, denumireEveniment);
	this->time = new Time(t);
	this->date = new Date(d);
}

Eveniment::Eveniment(Eveniment& e) {
	Utils::copyChar(this->denumireEveniment, e.denumireEveniment);
	this->time = new Time(*e.time);
	this->date = new Date(*e.date);
}

Eveniment::~Eveniment() {
	Utils::deallocChar(this->denumireEveniment);
}

Eveniment& Eveniment::operator=(Eveniment& e) {
	if (this != &e) {
		Utils::copyChar(this->denumireEveniment, e.denumireEveniment);
		this->time = e.time;
		this->date = e.date;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Eveniment e) {
	out << e.denumireEveniment;
	out << e.time;
	out << e.date;
	return out;
}
std::istream& operator>>(std::istream& in, Eveniment& e) {

	return in;
}

char* Eveniment::getDenumireEveniment() {
	char* copy = nullptr;
	Utils::copyChar(copy, this->denumireEveniment);
	return copy;
}

void Eveniment::setDenumireEveniment(const char* denumireEveniment) {
	Utils::copyChar(this->denumireEveniment, denumireEveniment);
}

Time Eveniment::getTime() {
	return *this->time;
}

void Eveniment::setTime(const unsigned hour, const unsigned minute) {
	this->time->setHour(hour);
	this->time->setMinute(minute);
}

Date Eveniment::getDate() {
	return *this->date;
}

void Eveniment::setDate(const unsigned day, const unsigned month, const unsigned year) {
	this->date->setDay(day);
	this->date->setMonth(month);
	this->date->setYear(year);
}