#pragma once
#include "Date.h"
class Expense
{
	int incomeId, userId;
	Date date;
	std::string item, amount;
public:
	Expense();
	~Expense();
};

