#include "Date.h"

Date::Date(int YEAR, int MONTH, int DAY)
	:year(YEAR), month(MONTH), day(DAY)
{
	if (isYearLeap())
		monthDayCount = std::vector<int>{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	else
		monthDayCount = std::vector<int>{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
}

Date::Date()
	:year(2000), month(1), day(1)
{

}

bool Date::isYearLeap()
{
	if (year % 4 != 0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 != 0)
		return false;
	else
		return true;
}


Date::~Date()
{
}
