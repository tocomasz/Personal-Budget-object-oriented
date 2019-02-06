#pragma once
#include <iostream>
#include <vector>
#include "Date.h"
#include "Income.h"
#include "Markup.h"
class BudgetFile
{
	const std::string incomesFileName, expensesFileName;
public:
	BudgetFile(std::string, std::string);
	void saveIncomeToFile(Income, int);
	std::vector<Income> loadLoggedUserIncomesFromFile(int);
	int getLastIncomeIdFromFile();
	int getLastExpenseIdFromFile();
	~BudgetFile();
};

