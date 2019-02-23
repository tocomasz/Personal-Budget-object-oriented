#pragma once
#include <vector>
#include "HelperClass.h"
class Date
{
	int year, month, day;

	bool isYearLeap();
public:
	std::vector<int> monthDayCount;

	Date(int year, int month, int day);
	Date(std::string);
	Date();

	int getYear();
	int getMonth();
	int getDay();
	std::string getDateAsString();

	bool isDateValid();
	~Date();
};

