#include <iostream>
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
#include <Aspose.PDF.Cpp/Document.h>
#include <Aspose.PDF.Cpp/Page.h>
#include <Aspose.PDF.Cpp/PageCollection.h>
#include <Aspose.PDF.Cpp/Color.h>
#include <Aspose.PDF.Cpp/Text/TextFragment.h>
#include <Aspose.PDF.Cpp/Text/Position.h>
#include <Aspose.PDF.Cpp/Text/TextBuilder.h>
#include <Aspose.PDF.Cpp/Text/TextFragmentCollection.h>
#include <Aspose.PDF.Cpp/Text/TextFragmentState.h>
#include <Aspose.PDF.Cpp/Text/FontRepository.h>

using namespace Aspose::Pdf;
using namespace Aspose::Pdf::Text;

int main(int argc, char* argv[])
{
	std::string currentPath = argv[0];
	currentPath.resize(currentPath.find_last_of("\\/"));
	std::cout << "Current path: " << currentPath << std::endl;

	//Date d(20, 2, 2023);
	////std::cout << d.DateFormatted('-');

	//Time t(23, 59);
	////std::cout << t.timeFormatted(':');

	//Locatie l("testttt", 5, 4);

	//Eveniment eveniment_cool((const char*)"testttttt", 2, l, t, d);

	///*std::cout << eveniment_cool << std::endl;

	//++eveniment_cool;

	//std::cout << eveniment_cool << std::endl;*/

	////std::cout << eveniment_cool.getLocatie()[1][2];

	//Bilet b(eveniment_cool);

	//l + 2;

	//unsigned* test = new unsigned[2];
	//test[0] = 2;
	//test[1] = 4;

	//l.setRanduriVip(test, 2);

	////system("CLS");

	////std::cin >> l;

	///*std::cin >> b;

	//std::cout << b;*/

	////b.renuntareBilet();

	return 0;
}