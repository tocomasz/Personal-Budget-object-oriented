#include "HelperClass.h"



HelperClass::HelperClass()
{
}

void HelperClass::pauseProgram()
{
	std::string temp;
	std::cout << "Nacisnij enter aby kontynuowac..";
	getline(std::cin, temp);
	return;
}


HelperClass::~HelperClass()
{
}
