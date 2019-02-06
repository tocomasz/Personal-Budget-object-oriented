#include "Income.h"

Income::Income()
{
}

void Income::setDate(Date dateFromUser)
{
	date = dateFromUser;
}

void Income::setItem(std::string newItem)
{
	item = newItem;
}

void Income::setAmount(double newAmount)
{
	amount = newAmount;
}

void Income::setIncomeId(int newId)
{
	incomeId = newId;
}

void Income::setUserId(int newId)
{
	userId = newId;
}

Date Income::getDate()
{
	return date;
}

std::string Income::getItem()
{
	return item;
}

double Income::getAmount()
{
	return amount;
}

int Income::getIncomeId()
{
	return incomeId;
}

int Income::getUserId()
{
	return userId;
}

Income::~Income()
{
}
