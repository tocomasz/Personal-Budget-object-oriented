#include "BudgetFile.h"

BudgetFile::BudgetFile(std::string INCOMESFILENAME, std::string EXPENSEFILENAME)
	:incomesFileName(INCOMESFILENAME), expensesFileName(EXPENSEFILENAME)
{

}

void BudgetFile::saveIncomeToFile(Income income, int loggedUserId)
{
	CMarkup xml;
	xml.Load(incomesFileName);
	if (xml.FindElem("INCOMES") == false)
		xml.AddElem("INCOMES");
	else
		xml.ResetMainPos();
	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("INCOME");
	xml.SetAttrib("userId", income.getUserId());
	xml.IntoElem();
	xml.AddElem("INCOMEID", income.getIncomeId());
	xml.AddElem("DATE");
	xml.IntoElem();
	xml.AddElem("YEAR", income.getDate().getYear());
	xml.AddElem("MONTH", income.getDate().getMonth());
	xml.AddElem("DAY", income.getDate().getDay());
	xml.OutOfElem();
	xml.AddElem("ITEM", income.getItem());
	xml.AddElem("AMOUNT", HelperClass::doubleToString(income.getAmount()));
	xml.OutOfElem();

	xml.Save(incomesFileName);
}

void BudgetFile::saveExpenseToFile(Expense expense, int loggedUserId)
{
	CMarkup xml;
	xml.Load(expensesFileName);
	if (xml.FindElem("EXPENSES") == false)
		xml.AddElem("EXPENSES");
	else
		xml.ResetMainPos();
	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("EXPENSE");
	xml.SetAttrib("userId", expense.getUserId());
	xml.IntoElem();
	xml.AddElem("EXPENSEEID", expense.getExpenseId());
	xml.AddElem("DATE");
	xml.IntoElem();
	xml.AddElem("YEAR", expense.getDate().getYear());
	xml.AddElem("MONTH", expense.getDate().getMonth());
	xml.AddElem("DAY", expense.getDate().getDay());
	xml.OutOfElem();
	xml.AddElem("ITEM", expense.getItem());
	xml.AddElem("AMOUNT", HelperClass::doubleToString(expense.getAmount()));
	xml.OutOfElem();

	xml.Save(expensesFileName);
}

std::vector<Income> BudgetFile::loadLoggedUserIncomesFromFile(int loggedUserId)
{
	std::vector<Income> incomes;
	CMarkup xml;
	xml.Load(incomesFileName);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("INCOME"))
	{
		if (HelperClass::stringToInt(xml.GetAttrib("userId")) == loggedUserId)
		{
			Income income;
			income.setUserId(loggedUserId);

			xml.IntoElem();
			xml.FindElem("INCOMEID");
			income.setIncomeId(HelperClass::stringToInt(xml.GetData()));

			int year, month, day;
			xml.FindElem("DATE");
			xml.IntoElem();
			xml.FindElem("YEAR");
			year = HelperClass::stringToInt(xml.GetData());
			xml.FindElem("MONTH");
			month = HelperClass::stringToInt(xml.GetData());
			xml.FindElem("DAY");
			day = HelperClass::stringToInt(xml.GetData());
			income.setDate(Date(year, month, day));
			xml.OutOfElem();

			xml.FindElem("ITEM");
			income.setItem(xml.GetData());

			xml.FindElem("AMOUNT");
			income.setAmount(HelperClass::stringToDouble(xml.GetData()));
			xml.OutOfElem();
			incomes.push_back(income);
		}
	}
	return incomes;
}


std::vector<Expense> BudgetFile::loadLoggedUserExpensesFromFile(int loggedUserId)
{
	std::vector<Expense> expenses;
	CMarkup xml;
	xml.Load(expensesFileName);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("EXPENSE"))
	{
		if (HelperClass::stringToInt(xml.GetAttrib("userId")) == loggedUserId)
		{
			Expense expense;
			expense.setUserId(loggedUserId);

			xml.IntoElem();
			xml.FindElem("EXPENSEID");
			expense.setExpenseId(HelperClass::stringToInt(xml.GetData()));

			int year, month, day;
			xml.FindElem("DATE");
			xml.IntoElem();
			xml.FindElem("YEAR");
			year = HelperClass::stringToInt(xml.GetData());
			xml.FindElem("MONTH");
			month = HelperClass::stringToInt(xml.GetData());
			xml.FindElem("DAY");
			day = HelperClass::stringToInt(xml.GetData());
			expense.setDate(Date(year, month, day));
			xml.OutOfElem();

			xml.FindElem("ITEM");
			expense.setItem(xml.GetData());

			xml.FindElem("AMOUNT");
			expense.setAmount(HelperClass::stringToDouble(xml.GetData()));
			xml.OutOfElem();
			expenses.push_back(expense);
		}
	}
	return expenses;
}

int BudgetFile::getLastIncomeIdFromFile()
{
	CMarkup xml;
	xml.Load(incomesFileName);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem())
	{
	}
	xml.IntoElem();
	xml.FindElem("INCOMEID");
	return HelperClass::stringToInt(xml.GetData());
}

int BudgetFile::getLastExpenseIdFromFile()
{
	CMarkup xml;
	xml.Load(expensesFileName);
	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem())
	{
	}
	xml.IntoElem();
	xml.FindElem("EXPENSEID");
	return HelperClass::stringToInt(xml.GetData());
}

BudgetFile::~BudgetFile()
{
}
