#include "Date.h"
#include "Utils.h"

Date::Date() {

	std::tm* curr = Utils::getCurrentDate();

	this->day = curr->tm_mday;
	this->month = curr->tm_mon + 1;
	this->year = curr->tm_year + 1900;
};

Date::Date(const unsigned day, const unsigned month, const unsigned year):Date::Date() {
	if (Utils::validateDate(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

Date::Date(Date& d) {
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

Date::~Date() {}

Date& Date::operator=(Date& d) {
	if (this != &d) {
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Date& d) {
	unsigned day, month, year;
	std::cout << "Introduceti ziua: ";
	in >> day;
	while (in.fail() || day < 1 || day > 31) {
		in.clear();
		in.ignore(1000, '\n');
		std::cout << "Ziua trebuie sa fie un numar intreg pozitiv!" << std::endl;
		in >> day;
	}
	std::cout << "Introduceti luna: ";
	in >> month;
	while (in.fail() || month < 1 || month > 12) {
		in.clear();
		in.ignore(1000, '\n');
		std::cout << "Luna trebuie sa fie un numar intreg pozitiv!" << std::endl;
		in >> day;
	}
	std::cout << "Introduceti anul: ";
	in >> year;
	while (in.fail() || year <= 2022) {
		in.clear();
		in.ignore(1000, '\n');
		std::cout << "Anul trebuie sa fie un numar intreg pozitiv (si mai cel putin 2022)!" << std::endl;
		in >> day;
	}
	while (!Utils::validateDate(day, month, year)) {
		std::cout << "Ati introdus o data invalida! Reintroduceti:" << std::endl;
		std::cout << "ziua: ";
		in >> day;
		while (in.fail() || day < 1 || day > 31) {
			in.clear();
			in.ignore(1000, '\n');
			std::cout << "Ziua trebuie sa fie un numar intreg pozitiv!" << std::endl;
			in >> day;
		}
		std::cout << "luna: ";
		in >> month;
		while (in.fail() || month < 1 || month > 12) {
			in.clear();
			in.ignore(1000, '\n');
			std::cout << "Luna trebuie sa fie un numar intreg pozitiv!" << std::endl;
			in >> day;
		}
		std::cout << "anul: ";
		in >> year;
		while (in.fail() || year <= 2022) {
			in.clear();
			in.ignore(1000, '\n');
			std::cout << "Anul trebuie sa fie un numar intreg pozitiv (si mai cel putin 2022)!" << std::endl;
			in >> day;
		}
	}
	d.day = day;
	d.month = month;
	d.year = year;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Date d) {
	out << "Zi: " << d.day << std::endl;
	out << "Luna: " << d.month << std::endl;
	out << "An: " << d.year;
	return out;
}

unsigned Date::getDay() {
	return day;
}

void Date::setDay(const unsigned day) {
	if (Utils::validateDate(day, this->month, this->year)) {
		this->day = day;
	}
}

unsigned Date::getMonth() {
	return month;
}

void Date::setMonth(const unsigned month) {
	if (Utils::validateDate(this->day, month, this->year)) {
		this->month = month;
	}
}

unsigned Date::getYear() {
	return year;
}

void Date::setYear(const unsigned year) {
	if (Utils::validateDate(this->day, this->month, year)) {
		this->year = year;
	}
}

std::string Date::DateFormatted(const char separator) {
	std::string dateFormatted;
	if (std::to_string(day).length() == 1) {
		dateFormatted += '0';
	}
	dateFormatted += std::to_string(day);
	dateFormatted += separator;
	if (std::to_string(month).length() == 1) {
		dateFormatted += '0';
	}
	dateFormatted += std::to_string(month);
	dateFormatted += std::to_string(year);
	return dateFormatted;
}