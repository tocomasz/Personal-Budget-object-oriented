#include <iostream>
#include "PersonalBudget.h"

char mainMenu()
{
	char ch;

	system("cls");
	std::cout << "    >>> MENU  GLOWNE <<<" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "1. Rejestracja" << std::endl;
	std::cout << "2. Logowanie" << std::endl;
	std::cout << "9. Koniec programu" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Twoj wybor: ";
	ch = HelperClass::loadCharacter();

	return ch;
}

char userMenu()
{
	char ch;

	system("cls");
	std::cout << " >>> MENU UZYTKOWNIKA <<<" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "1. Dodaj przychod" << std::endl;
	std::cout << "2. Dodaj wydatek" << std::endl;
	std::cout << "3. Bilans z biezacego miesiaca" << std::endl;
	std::cout << "4. Bilans z poprzedniego miesiaca" << std::endl;
	std::cout << "5. Bilans z wybranego okresu" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "6. Zmien haslo" << std::endl;
	std::cout << "7. Wyloguj sie" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Twoj wybor: ";
	ch = HelperClass::loadCharacter();

	return ch;
}


int main()
{
	PersonalBudget pb("users.xml", "incomes.xml", "expenses.xml");

	char choice;
	while (true)
	{
		if (pb.getLoggedUserId() == 0)
		{
			choice = mainMenu();
			switch (choice)
			{
			case '1':
				pb.registerUser();
				break;
			case '2':
				pb.logUserIn();
				break;
			case '9':
				exit(0);
				break;
			default:
				std::cout << std::endl << "Nie ma takiej opcji w menu." << std::endl;
				HelperClass::pauseProgram();
				break;
			}
		}
		else
		{
			choice = userMenu();
			switch (choice)
			{
			case '1':
				pb.addIncome();
				break;
			case '2':
				pb.addExpense();
				break;
			case '3':
				pb.showCurrentMonthBalance();
				break;
			case '4':
				pb.showLastMonthBalance();
				break;
			case '5':
				pb.showCustomPeriodBalance();
				break;
			case '6':
				pb.changeUserPassword();
				break;
			case '7':
				pb.logUserOut();
				break;
			}
		}

	}
}

