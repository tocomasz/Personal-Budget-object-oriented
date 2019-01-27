#include "PersonalBudget.h"



PersonalBudget::PersonalBudget(std::string USERSFILENAME, std::string INCOMESFILENAME, std::string EXPENSESFILENAME)
	: userManager(USERSFILENAME), INCOMES_FILE_NAME(INCOMESFILENAME), EXPENSES_FILE_NAME(EXPENSESFILENAME)
{

}

void PersonalBudget::registerUser()
{
	userManager.registerUser();
}

void PersonalBudget::logUserIn()
{
	userManager.logUserIn();
}

void PersonalBudget::changeUserPassword()
{
	userManager.changeUserPassword();
}

void PersonalBudget::logUserOut()
{
	userManager.logUserOut();
}


PersonalBudget::~PersonalBudget()
{
}
