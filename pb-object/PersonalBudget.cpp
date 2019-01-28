#include "PersonalBudget.h"



PersonalBudget::PersonalBudget(std::string USERSFILENAME, std::string INCOMESFILENAME, std::string EXPENSESFILENAME)
	: userManager(USERSFILENAME), INCOMES_FILE_NAME(INCOMESFILENAME), EXPENSES_FILE_NAME(EXPENSESFILENAME)
{
	budgetManager = NULL;
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


PersonalBudget::~PersonalBudget()
{
	delete budgetManager;
	budgetManager = NULL;
}
