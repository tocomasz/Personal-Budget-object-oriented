#include "Date.h"

Date::Date(int YEAR, int MONTH, int DAY)
	:year(YEAR), month(MONTH), day(DAY)
{
	if (isYearLeap())
		monthDayCount = std::vector<int>{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	else
		monthDayCount = std::vector<int>{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
}
Date::Date(std::string dateAsString)
{
	size_t yearEnd = dateAsString.find('-');
	size_t monthEnd = dateAsString.find('-', yearEnd + 1);

	year = HelperClass::stringToInt(dateAsString.substr(0, yearEnd));
	month = HelperClass::stringToInt(dateAsString.substr(yearEnd + 1, monthEnd));
	day = HelperClass::stringToInt(dateAsString.substr(monthEnd + 1));
	
	if (isYearLeap())
		monthDayCount = std::vector<int>{ 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	else
		monthDayCount = std::vector<int>{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
}

Date::Date()
	:year(2000), month(1), day(1)
{
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
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

bool Date::isDateValid()
{
	if (year < 2000 || month <= 0 || month > 12 || day <= 0)
		return false;
	else if (day > monthDayCount[month])
		return false;
	else
		return true;
}


Date::~Date()
{
}
