#include <iostream>
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"

int main()
{
    Date d(20,2,2023);
    //std::cout << d.DateFormatted('-');

    Time t(23, 59);
    //std::cout << t.timeFormatted(':');

    Locatie l("Baneasa", 20, 4);
    
    Eveniment eveniment_cool((const char*)"Strip club", 2, l, t, d);


    /*std::cout << eveniment_cool << std::endl;

    ++eveniment_cool;

    std::cout << eveniment_cool << std::endl;*/

    //std::cout << eveniment_cool.getLocatie()[1][2];
    
    Bilet b(eveniment_cool);

    l + 2;
    
    unsigned* test = new unsigned[2];
    test[0] = 2;
    test[1] = 4;
    
    l.setRanduriVip(test, 2);
    
    system("CLS");

    std::cin >> b;

    std::cout << b;

    b.renuntareBilet();

    std::cout << b;

    
    return 0;
}