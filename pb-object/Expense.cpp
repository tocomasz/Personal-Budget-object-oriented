#include "Expense.h"

Expense::Expense()
{
}

void Expense::setDate(Date dateFromUser)
{
	date = dateFromUser;
}

void Expense::setItem(std::string newItem)
{
	item = newItem;
}

void Expense::setAmount(double newAmount)
{
	amount = newAmount;
}

void Expense::setExpenseId(int newId)
{
	expenseId = newId;
}

void Expense::setUserId(int newId)
{
	userId = newId;
}

Date Expense::getDate()
{
	return date;
}

std::string Expense::getItem()
{
	return item;
}

double Expense::getAmount()
{
	return amount;
}

int Expense::getExpenseId()
{
	return expenseId;
}

int Expense::getUserId()
{
	return userId;
}


Expense::~Expense()
{
}
