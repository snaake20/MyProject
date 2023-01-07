#include "Menu.h"

void Menu::fetchLocatii()
{
	
}

void Menu::fetchEvenimente()
{
}

void Menu::fetchBilete()
{
}


void Menu::showMainMenu()
{
  system("cls");
  std::cout << "-------- Meniu IaBilet --------" << std::endl;
  std::cout << "1. Locatie" << std::endl;
  std::cout << "2. Eveniment" << std::endl;
  std::cout << "3. Tichet" << std::endl;
	std::cout << "4. Exit" << std::endl;

  int optiune;
  std::cout << "Alegeti o optiune: ";
  std::cin >> optiune;

  switch (optiune) {
  case 1:
    std::cout << "Locatie" << std::endl;
    Menu::showLocatieMenu();
    break;
  case 2:
    std::cout << "Eveniment" << std::endl;
    Menu::showEvenimentMenu();
    break;
  case 3:
    std::cout << "Tichet" << std::endl;
    Menu::showBiletMenu();
    break;
	case 4:
		//stop program
    exit(0);
		break;
  default:
    std::cout << "Optiune invalida" << std::endl;
    Menu::showMainMenu();
    break;
  }
}

void Menu::showLocatieMenu()
{
  system("cls");
  std::cout << "-------- Locatie --------" << std::endl;
  std::cout << "1. Adauga locatie" << std::endl;
  std::cout << "2. Sterge locatie" << std::endl;
  std::cout << "3. Modifica locatie" << std::endl;
  std::cout << "4. Afiseaza locatii" << std::endl;
	std::cout << "5. Inapoi la meniul principal" << std::endl;

  unsigned optiune;
  std::cout << "Alegeti o optiune: ";
  std::cin >> optiune;

  switch (optiune) {
  case 1:
    std::cout << "Adauga locatie" << std::endl;
    break;
  case 2:
    std::cout << "Elimina locatie" << std::endl;
    break;
  case 3:
    std::cout << "Modifica locatie" << std::endl;
    break;
  case 4:
    std::cout << "Afiseaza locatii" << std::endl;
    break;
	case 5:
		Menu::showMainMenu();
    break;
  default:
    std::cout << "Optiune invalida" << std::endl;
    Menu::showLocatieMenu();
    break;
  }
}

void Menu::showEvenimentMenu()
{
  system("cls");
  std::cout << "-------- Eveniment --------" << std::endl;
  std::cout << "1. Adauga eveniment" << std::endl;
  std::cout << "2. Sterge eveniment" << std::endl;
  std::cout << "3. Modifica eveniment" << std::endl;
  std::cout << "4. Afiseaza evenimente" << std::endl;
  std::cout << "5. Inapoi la meniul principal" << std::endl;

  unsigned optiune;
  std::cout << "Alegeti o optiune: ";
  std::cin >> optiune;

  //TODO use func from utils requireUnsigned

  switch (optiune) {
  case 1:
    std::cout << "Adauga eveniment" << std::endl;
    break;
  case 2:
    std::cout << "Elimina eveniment" << std::endl;
    break;
  case 3:
    std::cout << "Modifica eveniment" << std::endl;
    break;
  case 4:
		std::cout << "Afiseaza evenimente" << std::endl;
    break;
  case 5:
    Menu::showMainMenu();
    break;
  default:
    std::cout << "Optiune invalida" << std::endl;
    Menu::showEvenimentMenu();
    break;
  }
}

void Menu::showBiletMenu()
{
  system("cls");
	std::cout << "-------- Bilet --------" << std::endl;
	std::cout << "1. Adauga bilet" << std::endl;
	std::cout << "2. Sterge bilet" << std::endl;
	std::cout << "3. Modifica bilet" << std::endl;
	std::cout << "4. Afiseaza bilete" << std::endl;
  std::cout << "5. Inapoi la meniul principal" << std::endl;

	unsigned optiune;
	std::cout << "Alegeti o optiune: ";
	std::cin >> optiune;

	switch (optiune) {
	case 1:
		std::cout << "Adauga bilet" << std::endl;
		break;
	case 2:
		std::cout << "Elimina bilet" << std::endl;
		break;
	case 3:
		std::cout << "Modifica bilet" << std::endl;
		break;
	case 4:
		std::cout << "Afiseaza bilete" << std::endl;
		break;
  case 5:
    Menu::showMainMenu();
    break;
	default:
		std::cout << "Optiune invalida" << std::endl;
		Menu::showBiletMenu();
		break;
	}
}