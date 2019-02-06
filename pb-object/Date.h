#pragma once
#include <vector>
#include "HelperClass.h"
class Date
{
	int year, month, day;

	bool isYearLeap();
public:
	std::vector<int> monthDayCount;
	int getYear();
	int getMonth();
	int getDay();
	Date(int, int, int);
	Date(std::string);
	Date();
	bool isDateValid();
	~Date();
};

