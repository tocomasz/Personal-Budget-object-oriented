#include <iostream>
#include "PersonalBudget.h"
int main()
{
	PersonalBudget pb("users.xml", "incomes.xml", "expenses.xml");
	pb.logUserIn();
	pb.changeUserPassword();
	pb.logUserOut();
	pb.changeUserPassword();

	
}

