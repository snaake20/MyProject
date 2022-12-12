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

    Eveniment eveniment_cool((const char*)"Strip club", t, d);


    //std::cout << eveniment_cool << std::endl;

    /*++eveniment_cool;

    std::cout << eveniment_cool << std::endl;

    Bilet b(2, 3, true, eveniment_cool);

    std::cout << b << std::endl;

    std::cin >> eveniment_cool;
    
    std::cout << b << std::endl;*/
    
    Locatie l("Baneasa", 20, 4);
    
    std::cout << l << std::endl;
    
    l + 2;
    
    std::cout << l;
    
    return 0;
}