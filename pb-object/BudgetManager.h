#pragma once
#include <vector>
#include "BudgetFile.h"
#include "DateManager.h"
#include "Expense.h"
#include "HelperClass.h"
#include "Income.h"

class BudgetManager
{
	std::vector<Income> incomes, expenses;
	int loggedUserId;
	int lastIncomeId, lastExpenseId;
	BudgetFile budgetFile;
	DateManager dateManager;

	Income provideNewIncomeData();
	Expense provideNewExpenseData();
public:
	BudgetManager(std::string, std::string, int);
	void addNewIncomeRecord();
	~BudgetManager();
};

