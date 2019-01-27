#pragma once
#include <iostream>
class BudgetFile
{
	const std::string incomesFileName, expensesFileName;
public:
	BudgetFile(std::string, std::string);
	~BudgetFile();
};

