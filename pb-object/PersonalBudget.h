#pragma once
#include <iostream>
#include "UserManager.h"
class PersonalBudget
{
	const std::string INCOMES_FILE_NAME, EXPENSES_FILE_NAME;
	UserManager userManager;
public:
	PersonalBudget(std::string, std::string, std::string);
	void registerUser();
	void logUserIn();
	void changeUserPassword();
	void logUserOut();
	~PersonalBudget();
};

