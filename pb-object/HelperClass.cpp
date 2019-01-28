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

char HelperClass::loadCharacter()
{
	std::string input = "";
	char ch = { 0 };
	while (true)
	{

		getline(std::cin, input);

		if (input.length() == 1)
		{
			ch = input[0];
			break;
		}
		std::cout << "To nie jest pojedynczy znak. Wpisz ponownie." << std::endl;
	}
	return ch;
}

std::string HelperClass::loadLine()
{
	std::cin >> (std::ws);
	std::string input = "";
	getline(std::cin, input);
	return input;
}

std::string HelperClass::intToString(int number)
{
	std::ostringstream ss;
	ss << number;
	std::string str = ss.str();
	return str;
}



HelperClass::~HelperClass()
{
}
