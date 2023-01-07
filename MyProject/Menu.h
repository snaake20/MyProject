#pragma once
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"
#include <list>
#include <unordered_map>
#include <string>
#include <fstream>

class Menu
{
private:
	std::list<Locatie> locatii;
	std::list<Eveniment> evenimente;
	std::unordered_map<std::string, Bilet> bilete;
public:

	void fetchLocatii();
	void fetchEvenimente();
	void fetchBilete();
	
	void showMainMenu();
	void showLocatieMenu();
	void showEvenimentMenu();
	void showBiletMenu();
	
};

