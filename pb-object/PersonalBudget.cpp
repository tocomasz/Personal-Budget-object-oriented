#include "PersonalBudget.h"



PersonalBudget::PersonalBudget(std::string USERSFILENAME, std::string INCOMESFILENAME, std::string EXPENSESFILENAME)
	: userManager(USERSFILENAME), INCOMES_FILE_NAME(INCOMESFILENAME), EXPENSES_FILE_NAME(EXPENSESFILENAME)
{

}


PersonalBudget::~PersonalBudget()
{
}
