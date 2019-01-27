#pragma once
#include "Date.h"
class Income
{
	int incomeId, userId;
	Date date;
	std::string item, amount;
	
public:
	Income();
	~Income();
};

