#include "CiD.h"

std::string CiD::caracterePosibile = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//generate uuid
std::string CiD::generateCiD()
{
	std::string uuid = "";
	for (int i = 0; i < 8; i++)
	{
		uuid += caracterePosibile[rand() % caracterePosibile.length()];
	}
	uuid += "-";
	for (int i = 0; i < 4; i++)
	{
		uuid += caracterePosibile[rand() % caracterePosibile.length()];
	}
	uuid += "-";
	for (int i = 0; i < 4; i++)
	{
		uuid += caracterePosibile[rand() % caracterePosibile.length()];
	}
	uuid += "-";
	for (int i = 0; i < 4; i++)
	{
		uuid += caracterePosibile[rand() % caracterePosibile.length()];
	}
	uuid += "-";
	for (int i = 0; i < 12; i++)
	{
		uuid += caracterePosibile[rand() % caracterePosibile.length()];
	}
	return uuid;
}
