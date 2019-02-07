#pragma once
#include "Date.h"
class Expense
{
	int expenseId, userId;
	Date date;
	std::string item;
	double amount;
public:
	Expense();

	void setDate(Date);
	void setItem(std::string);
	void setAmount(double);
	void setExpenseId(int);
	void setUserId(int);

	Date getDate();
	std::string getItem();
	double getAmount();
	int getExpenseId();
	int getUserId();

	~Expense();
};

