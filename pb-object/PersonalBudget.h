#pragma once
#include <iostream>
#include "BudgetManager.h"
#include "UserManager.h"
class PersonalBudget
{
	const std::string INCOMES_FILE_NAME, EXPENSES_FILE_NAME;
	UserManager userManager;
	BudgetManager *budgetManager;
public:
	PersonalBudget(std::string, std::string, std::string);

	int getLoggedUserId();
	void registerUser();
	void logUserIn();
	void changeUserPassword();
	void logUserOut();
	void addIncome();
	void addExpense();
	void showCurrentMonthBalance();
	void showLastMonthBalance();
	void showCustomPeriodBalance();

	~PersonalBudget();
};

