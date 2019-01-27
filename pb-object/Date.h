#pragma once
#include <vector>
class Date
{
	int year, month, day;

	bool isYearLeap();

public:
	std::vector<int> monthDayCount;
	Date(int, int, int);
	Date();

	~Date();
};

