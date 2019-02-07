#pragma once
#include <iostream>
#include <ctime>
#include "Date.h"
#include "HelperClass.h"
class DateManager
{
	std::string loadDate();
	std::string getCurrentDate();
public:
	DateManager();
	Date pickDateMenu();

	~DateManager();
};

