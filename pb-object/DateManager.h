#pragma once
#include <iostream>
#include <ctime>
#include "Date.h"
#include "HelperClass.h"
class DateManager
{
	std::string loadDate();

public:
	DateManager();

	Date pickDateMenu();
	Date getCurrentDate();
	Date getFirstDayOfPreviousMonth();
	static bool isEarlierOrEqual(Date, Date);
	static bool isEarlier(Date, Date);
	
	~DateManager();
};

