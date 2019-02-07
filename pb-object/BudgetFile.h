#pragma once
#include <iostream>
#include <vector>
#include "Date.h"
#include "Expense.h"
#include "Income.h"
#include "Markup.h"
class BudgetFile
{
	const std::string incomesFileName, expensesFileName;
public:
	BudgetFile(std::string, std::string);
	void saveIncomeToFile(Income, int);
	void saveExpenseToFile(Expense, int);
	std::vector<Income> loadLoggedUserIncomesFromFile(int);
	std::vector<Expense> loadLoggedUserExpensesFromFile(int);
	int getLastIncomeIdFromFile();
	int getLastExpenseIdFromFile();
	~BudgetFile();
};

