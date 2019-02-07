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
	if (number == "")
		return 0;
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

double HelperClass::stringToDouble(std::string number)
{
	number = replaceCommaWithDot(number);
	double doubleNumber;
	std::istringstream iss(number);
	iss >> doubleNumber;

	return doubleNumber;
}

std::string HelperClass::replaceCommaWithDot(std::string stringWithCommas)
{
	size_t pos = stringWithCommas.find(',');
	while (pos != std::string::npos)
	{
		stringWithCommas.replace(pos, 1, ".");
		pos = stringWithCommas.find(',');
	}
	return stringWithCommas;
}

std::string HelperClass::doubleToString(double number)
{
	std::ostringstream ss;
	ss << number;
	std::string str = ss.str();
	return str;
}

HelperClass::~HelperClass()
{
}
