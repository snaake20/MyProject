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
    
    //Eveniment eveniment_cool((const char*)"Strip club", l, t, d);


    //std::cout << eveniment_cool << std::endl;

    /*++eveniment_cool;

    std::cout << eveniment_cool << std::endl;

    Bilet b(2, 3, true, eveniment_cool);

    std::cout << b << std::endl;

    std::cin >> eveniment_cool;
    
    std::cout << b << std::endl;*/
    
    
    std::cout << l << std::endl;
    
    
    l + 2;
    
	std::cout << l << std::endl;

    unsigned* test = new unsigned[2];
    test[0] = 2;
    test[1] = 4;
    
    l.setRanduriVip(test, 2);
    
    system("CLS");

    std::cout << l;
    
    return 0;
}