#pragma once
#include <vector>
#include "Expense.h"
#include "Income.h"

class BudgetManager
{
	std::vector<Income> incomes, expenses;
public:
	BudgetManager(std::string, std::string);
	~BudgetManager();
};

