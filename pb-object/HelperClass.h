#pragma once
#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>


class HelperClass
{

public:
	HelperClass();
	static void pauseProgram();
	static std::string convertStringToSentenceCase(std::string);
	static int stringToInt(std::string);
	static char loadCharacter();
	static std::string loadLine();
	static std::string intToString(int);
	static double stringToDouble(std::string);
	static std::string replaceCommaWithDot(std::string);
	static std::string doubleToString(double);
	~HelperClass();
};

