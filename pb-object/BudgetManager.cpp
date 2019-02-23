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

	std::cout << "Wybierz date przychodu: " << std::endl;
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

	std::cout << "Wybierz date wydatku: " << std::endl;
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
	Date currentDate = dateManager.getCurrentDate();
	Date startingDate(currentDate.getYear(), currentDate.getMonth(), 1);
	Date endingDate(currentDate.getYear(), currentDate.getMonth(), currentDate.monthDayCount[currentDate.getMonth()]);

	printBalanceFromDateToDate(startingDate, endingDate);
	HelperClass::pauseProgram();
}

void BudgetManager::printLastMonthBalance()
{
	system("cls");
	Date startingDate = dateManager.getFirstDayOfPreviousMonth();
	Date endingDate(startingDate.getYear(), startingDate.getMonth(), startingDate.monthDayCount[startingDate.getMonth()]);

	printBalanceFromDateToDate(startingDate, endingDate);
	HelperClass::pauseProgram();
}

void BudgetManager::printCustomPeriodBalance()
{
	system("cls");

	std::cout << "Wybierz date poczatkowa: " << std::endl;
	Date startingDate = dateManager.pickDateMenu();

	std::cout << "Wybierz date koncowa: " << std::endl;
	Date endingDate = dateManager.pickDateMenu();

	printBalanceFromDateToDate(startingDate, endingDate);
	HelperClass::pauseProgram();
}
void BudgetManager::printBalanceFromDateToDate(Date startingDate, Date endingDate)
{
	std::vector<Income> tempIncomes = sortAndFilterByTime(incomes, startingDate, endingDate);
	std::vector<Expense> tempExpenses = sortAndFilterByTime(expenses, startingDate, endingDate);

	double sum = 0, sumIncomes = 0, sumExpenses = 0;


	std::cout << "Wybrany przedzial czasowy: od " << startingDate.getDateAsString() << " do " << endingDate.getDateAsString() << std::endl;
	std::cout << "Zestawienie przychodow: " << std::endl;
	printHeaderRow();
	for (std::vector <Income>::iterator itr = tempIncomes.begin(), end = tempIncomes.end(); itr != end; itr++)
	{
		printRecord(*itr);
		sumIncomes += itr->getAmount();
	}
	std::cout<< std::setw(32) << std::right << "SUMA: " << sumIncomes << std::endl;

	std::cout << std::endl << "Zestawienie wydatkow: " << std::endl;
	printHeaderRow();
	for (std::vector <Expense>::iterator itr = tempExpenses.begin(), end = tempExpenses.end(); itr != end; itr++)
	{
		printRecord(*itr);
		sumExpenses += itr->getAmount();
	}
	std::cout << std::setw(32) << std::right << "SUMA: " << sumExpenses << std::endl;

	sum = sumIncomes - sumExpenses;
	std::cout << std::endl << "W wybranym okresie zanotowano " << ((sum >0) ? "nadwyzke" : "deficyt") << " o wartosci: " << sum << std::endl;
}
void BudgetManager::printRecord(Income income)
{
	std::cout << std::setw(12) << std::left << income.getDate().getDateAsString();
	std::cout << std::setw(20) << std::left << income.getItem();
	std::cout << std::setw(10) << std::left << income.getAmount() << std::endl;
}
void BudgetManager::printRecord(Expense expense)
{
	std::cout << std::setw(12) << std::left << expense.getDate().getDateAsString();
	std::cout << std::setw(20) << std::left << expense.getItem();
	std::cout << std::setw(10) << std::left << expense.getAmount() << std::endl;
}

void BudgetManager::printHeaderRow()
{
	std::cout << std::setw(12) << std::left << "[DATA]";
	std::cout << std::setw(20) << std::left << "[RODZAJ]";
	std::cout << std::setw(10) << std::left << "[KWOTA]" << std::endl;
}

void BudgetManager::calculateAndPrintSum(std::vector<Income> incomeRecords, std::vector<Expense> expenseRecords)
{
	double sum = 0, sumIncomes = 0, sumExpenses = 0;
	for (std::vector <Income>::iterator itr = incomeRecords.begin(), end = incomeRecords.end(); itr != end; itr++)
	{
		sumIncomes += itr->getAmount();
	}

	for (std::vector <Expense>::iterator itr = expenseRecords.begin(), end = expenseRecords.end(); itr != end; itr++)
	{
		sumExpenses -= itr->getAmount();
	}

	std::cout << std::endl<< std::setw(31) << std::right << "SUMA: " << sum << std::endl;
	std::cout << std::endl << "+ wartosc dodatnia oznacza nadwyzke w danym okresie" << std::endl;
	std::cout << "- wartosc ujemna oznacza deficyt w danym okresie" << std::endl;
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

std::vector<Expense> BudgetManager::sortAndFilterByTime(std::vector<Expense> inputVector, Date startingDay, Date endDay)
{
	std::vector<Expense> outputVector;
	for (std::vector <Expense>::iterator itr = inputVector.begin(), end = inputVector.end(); itr != end; itr++)
	{
		if (dateManager.isEarlierOrEqual(startingDay, itr->getDate()) && dateManager.isEarlierOrEqual(itr->getDate(), endDay))
			outputVector.push_back(*itr);
	}
	std::sort(outputVector.begin(), outputVector.end(), compareExpensesByDate);
	return outputVector;
}

bool BudgetManager::compareIncomesByDate(Income first, Income second)
{
	return DateManager::isEarlier(first.getDate(), second.getDate());
}

bool BudgetManager::compareExpensesByDate(Expense first, Expense second)
{
	return DateManager::isEarlier(first.getDate(), second.getDate());
}




BudgetManager::~BudgetManager()
{
}
