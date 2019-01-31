#pragma once
#include "Date.h"
class Income
{
	int incomeId, userId;
	Date date;
	std::string item;
	double amount;
public:
	Income();
	void setDate(Date);
	void setItem(std::string);
	void setAmount(double);
	void setIncomeId(int);
	void setUserId(int);
	~Income();
};

