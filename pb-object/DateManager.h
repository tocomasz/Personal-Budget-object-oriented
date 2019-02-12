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
	std::string getCurrentDate();
	static bool isEarlierOrEqual(Date, Date);
	static bool isEarlier(Date, Date);

	~DateManager();
};

