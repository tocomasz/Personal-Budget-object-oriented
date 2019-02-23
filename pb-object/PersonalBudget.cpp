#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(std::string USERSFILENAME, std::string INCOMESFILENAME, std::string EXPENSESFILENAME)
	: userManager(USERSFILENAME), INCOMES_FILE_NAME(INCOMESFILENAME), EXPENSES_FILE_NAME(EXPENSESFILENAME)
{
	budgetManager = NULL;
}

int PersonalBudget::getLoggedUserId()
{
	return userManager.getLoggedUserId();
}

void PersonalBudget::registerUser()
{
	userManager.registerUser();
}

void PersonalBudget::logUserIn()
{
	userManager.logUserIn();
	if (userManager.isUserLoggedIn())
	{
		budgetManager = new BudgetManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedUserId());
	}
}

void PersonalBudget::changeUserPassword()
{
	userManager.changeUserPassword();
}

void PersonalBudget::logUserOut()
{
	userManager.logUserOut();
}

void PersonalBudget::addIncome()
{
	budgetManager->addNewIncomeRecord();
}

void PersonalBudget::addExpense()
{
	budgetManager->addNewExpenseRecord();
}

void PersonalBudget::showCurrentMonthBalance()
{
	budgetManager->printCurrentMonthBalance();
}

void PersonalBudget::showLastMonthBalance()
{
	budgetManager->printLastMonthBalance();
}

void PersonalBudget::showCustomPeriodBalance()
{
	budgetManager->printCustomPeriodBalance();
}

PersonalBudget::~PersonalBudget()
{
	delete budgetManager;
	budgetManager = NULL;
}
