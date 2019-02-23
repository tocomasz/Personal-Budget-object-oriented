#pragma once

#include <algorithm>
#include <iomanip>
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
	std::vector<Expense> sortAndFilterByTime(std::vector<Expense>, Date, Date);
	void printRecord(Income);
	void printRecord(Expense);
	void printHeaderRow();
	void calculateAndPrintSum(std::vector<Income>, std::vector<Expense>);
	void printBalanceFromDateToDate(Date, Date);

public:
	BudgetManager(std::string, std::string, int);
	void addNewIncomeRecord();
	void addNewExpenseRecord();
	void printCurrentMonthBalance();
	void printLastMonthBalance();
	void printCustomPeriodBalance();
	static bool compareIncomesByDate(Income, Income);
	static bool compareExpensesByDate(Expense, Expense);
	~BudgetManager();
};

