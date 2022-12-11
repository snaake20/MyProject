#include <iostream>
#include "Bilet.h"
#include "Eveniment.h"

int main()
{
    Date d(20,2,2023);
    //std::cout << d.DateFormatted('-');

    Time t(23, 59);
    //std::cout << t.timeFormatted(':');

    Eveniment eveniment_cool((const char*)"Strip club", t, d);

    std::cin >> eveniment_cool;

    std::cout << eveniment_cool << std::endl;

    ++eveniment_cool;

    std::cout << eveniment_cool << std::endl;

    return 0;
}