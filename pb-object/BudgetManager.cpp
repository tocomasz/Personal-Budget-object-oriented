#include "BudgetManager.h"

BudgetManager::BudgetManager(std::string INCOMESFILENAME, std::string EXPENSESFILENAME, int LOGGEDUSERID)
	:budgetFile(INCOMESFILENAME, EXPENSESFILENAME), loggedUserId(LOGGEDUSERID)
{
	lastExpenseId = lastIncomeId = 0;
	//incomes = budgetFile.loadLoggedUserIncomesFromFile(loggedUserId);
	//expenses = budgetFile.loadLoggedUserExpensesFromFile(loggedUserId);

}

Income BudgetManager::provideNewIncomeData()
{
	Income income;
	income.setIncomeId(lastIncomeId++);
	income.setUserId(loggedUserId);

	income.setDate(dateManager.pickDateMenu());

	std::cout << "Wskaz czego dotyczy przychod: " << std::endl;
	income.setItem(HelperClass::loadLine());

	std::cout << "Podaj kwote:" << std::endl;
	income.setAmount(HelperClass::stringToDouble(HelperClass::loadLine()));

	return income;
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
