#pragma once

#include <algorithm>
#include <vector>
#include "BudgetFile.h"
#include "DateManager.h"
#include "Expense.h"
#include "HelperClass.h"
#include "Income.h"

class BudgetManager
{
	std::vector<Income> incomes;
	std::vector<Expense> expenses;
	int loggedUserId;
	int lastIncomeId, lastExpenseId;
	BudgetFile budgetFile;
	DateManager dateManager;

	Income provideNewIncomeData();
	Expense provideNewExpenseData();
	void updateLastIncomeAndExpenseId();
	std::vector<Income> sortAndFilterByTime(std::vector<Income>, Date, Date);
	void printIncome(Income);

public:
	BudgetManager(std::string, std::string, int);
	void addNewIncomeRecord();
	void addNewExpenseRecord();
	void printCurrentMonthBalance();
	static bool compareIncomesByDate(Income, Income);
	~BudgetManager();
};

