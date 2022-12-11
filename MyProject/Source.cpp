#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Bilet.h"
#include "Time.h"

int main()
{
    Date d(20,2,2023);
    std::cout << d.DateFormatted('-');

    Time t(23, 59);
    std::cout << t.timeFormatted(':');

    Eveniment eveniment_cool("Strip club", t, d);

    std::cout << eveniment_cool;

    return 0;
}