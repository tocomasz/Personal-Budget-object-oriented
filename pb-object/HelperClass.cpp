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

std::string HelperClass::convertStringToSentenceCase(std::string input)
{
	if (!input.empty())
	{
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		input[0] = toupper(input[0]);
	}
	return input;
}

int HelperClass::stringToInt(std::string number)
{
	int intNumber;
	std::istringstream iss(number);
	iss >> intNumber;

	return intNumber;
}


HelperClass::~HelperClass()
{
}
