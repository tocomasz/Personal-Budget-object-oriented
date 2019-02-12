#include "BudgetManager.h"

BudgetManager::BudgetManager(std::string INCOMESFILENAME, std::string EXPENSESFILENAME, int LOGGEDUSERID)
	:budgetFile(INCOMESFILENAME, EXPENSESFILENAME), loggedUserId(LOGGEDUSERID)
{
	lastExpenseId = lastIncomeId = 0;
	incomes = budgetFile.loadLoggedUserIncomesFromFile(loggedUserId);
	expenses = budgetFile.loadLoggedUserExpensesFromFile(loggedUserId);
	updateLastIncomeAndExpenseId();

}

Income BudgetManager::provideNewIncomeData()
{
	Income income;
	income.setIncomeId(++lastIncomeId);
	income.setUserId(loggedUserId);

	income.setDate(dateManager.pickDateMenu());

	std::cout << "Wskaz czego dotyczy przychod: " << std::endl;
	income.setItem(HelperClass::loadLine());

	std::cout << "Podaj kwote:" << std::endl;
	income.setAmount(HelperClass::stringToDouble(HelperClass::loadLine()));

	return income;
}

Expense BudgetManager::provideNewExpenseData()
{
	Expense expense;
	expense.setExpenseId(++lastExpenseId);
	expense.setUserId(loggedUserId);

	expense.setDate(dateManager.pickDateMenu());

	std::cout << "Wskaz czego dotyczy wydatek: " << std::endl;
	expense.setItem(HelperClass::loadLine());

	std::cout << "Podaj kwote:" << std::endl;
	expense.setAmount(HelperClass::stringToDouble(HelperClass::loadLine()));

	return expense;
}

void BudgetManager::addNewIncomeRecord()
{
	Income income = provideNewIncomeData();

	incomes.push_back(income);
	budgetFile.saveIncomeToFile(income, loggedUserId);

	std::cout << std::endl << "Dodano przychod" << std::endl;
	HelperClass::pauseProgram();
}

void BudgetManager::addNewExpenseRecord()
{
	Expense expense = provideNewExpenseData();

	expenses.push_back(expense);
	budgetFile.saveExpenseToFile(expense, loggedUserId);

	std::cout << std::endl << "Dodano wydatek" << std::endl;
	HelperClass::pauseProgram();
}

void BudgetManager::updateLastIncomeAndExpenseId()
{
	lastIncomeId = budgetFile.getLastIncomeIdFromFile();
	lastExpenseId = budgetFile.getLastExpenseIdFromFile();
}

void BudgetManager::printCurrentMonthBalance()
{
	system("cls");
	//print headers
	//create new temp sorted vector
	std::vector<Income> tempIncomes = sortAndFilterByTime(incomes, Date(2019, 02, 01), Date(dateManager.getCurrentDate()));

	//print all records
	for (std::vector <Income>::iterator itr = tempIncomes.begin(), end = tempIncomes.end(); itr != end; itr++)
	{
		printIncome(*itr);
	}
	//print sum
	HelperClass::pauseProgram();

}
void BudgetManager::printIncome(Income income)
{
	std::cout << income.getDate().getYear() <<"-" << income.getDate().getMonth() <<"-" << income.getDate().getDay() << "   ";
	std::cout << income.getItem() << "   ";
	std::cout << income.getAmount() << std::endl;
}

std::vector<Income> BudgetManager::sortAndFilterByTime(std::vector<Income> inputVector, Date startingDay, Date endDay)
{
	std::vector<Income> outputVector;
	for (std::vector <Income>::iterator itr = inputVector.begin(), end = inputVector.end(); itr != end; itr++)
	{
		if (dateManager.isEarlierOrEqual(startingDay, itr->getDate()) && dateManager.isEarlierOrEqual(itr->getDate(), endDay))
			outputVector.push_back(*itr);
	}
	std::sort(outputVector.begin(), outputVector.end(), compareIncomesByDate);
	return outputVector;
}

bool BudgetManager::compareIncomesByDate(Income first, Income second)
{
	return DateManager::isEarlier(first.getDate(), second.getDate());
}


BudgetManager::~BudgetManager()
{
}
