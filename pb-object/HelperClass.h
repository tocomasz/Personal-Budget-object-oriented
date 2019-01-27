#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
class HelperClass
{
public:
	HelperClass();
	static void pauseProgram();
	static std::string convertStringToSentenceCase(std::string);
	static int stringToInt(std::string);
	~HelperClass();
};

