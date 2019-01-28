#include "BudgetManager.h"



Income BudgetManager::provideNewIncomeData()
{
	Income income;
	income.setDate(dateManager.pickDateMenu());
	
	


	return income;
}

BudgetManager::BudgetManager(std::string INCOMESFILENAME, std::string EXPENSESFILENAME, int LOGGEDUSERID)
	:budgetFile(INCOMESFILENAME, EXPENSESFILENAME), loggedUserId(LOGGEDUSERID)
{
	//incomes = budgetFile.loadLoggedUserIncomesFromFile(loggedUserId);
	//expenses = budgetFile.loadLoggedUserExpensesFromFile(loggedUserId);

}

void BudgetManager::addNewIncomeRecord()
{
	Income income = provideNewIncomeData();

	incomes.push_back(income);
	//budgetFile.saveIncomesToFile(incomes);

	std::cout << std::endl << "Dodano przychod" << std::endl;
	HelperClass::pauseProgram();
}


BudgetManager::~BudgetManager()
{
}
