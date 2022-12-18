#include "Time.h"
#include "Utils.h"

Time::Time() {
	hour = 0;
	minute = 0;
};

Time::Time(unsigned hour, unsigned minute) {
	this->hour = Utils::validateHour(hour);
	this->minute = Utils::validateMinute(minute);
}

Time::Time(Time& t) {
	this->hour = t.hour;
	this->minute = t.minute;
}

Time::~Time() {}

Time& Time::operator=(Time& t) {
	if (this != &t) {
		this->hour = t.hour;
		this->minute = t.minute;
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Time& t) {
	unsigned temp;
	std::cout << "Introduceti ora: ";
	in >> temp;
	while (in.fail() || temp > 24) {
		in.clear();
		in.ignore(1000, '\n');
		std::cout << "Ora trebuie sa fie un numar intreg pozitiv!: ";
		in >> temp;
	}
	t.hour = temp;
	std::cout << "Introduceti minutul: ";
	in >> temp;
	while (in.fail() || temp > 60) {
		in.clear();
		in.ignore(1000, '\n');
		std::cout << "Minutul trebuie sa fie un numar intreg pozitiv!" << std::endl;
		in >> temp;
	}
	t.minute = temp;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Time t) {
	out << "Ora: " << t.hour << std::endl;
	out << "Minut: " << t.minute;
	return out;
}

unsigned Time::getHour() {
	return hour;
}

void Time::setHour(const unsigned hour) {
	if (hour >= 0 && hour <= 23)
		this->hour = hour;
}

unsigned Time::getMinute() {
	return minute;
}

void Time::setMinute(const unsigned minute) {
	if (minute >= 0 && minute <= 59)
		this->minute = minute;
}

std::string Time::timeFormatted(const char separator) {
	std::string timeFormatted;
	if (std::to_string(hour).length() == 1) {
		timeFormatted += '0';
	}
	timeFormatted += std::to_string(hour);
	timeFormatted += separator;
	if (std::to_string(minute).length() == 1) {
		timeFormatted += '0';
	}
	timeFormatted += std::to_string(minute);
	return timeFormatted;
}