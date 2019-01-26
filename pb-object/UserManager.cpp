#include "UserManager.h"

UserManager::UserManager(std::string USERSFILENAME)
	:userFile(USERSFILENAME)
{
	users = userFile.loadUsersFromFile();
	loggedUserId = 0;
}

int UserManager::newUserId()
{
	if (users.empty() == true)
		return 1;
	else
		return users.back().getUserId() + 1;
}

bool UserManager::isLoginTaken(std::string login)
{
	for (std::vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		if (itr->getLogin() == login)
		{
			std::cout << std::endl << "Istnieje uzytkownik o takim loginie." << std::endl;
			return true;
		}
	}
	return false;
}

User UserManager::provideNewUserLoginCredentials()
{
	User user;
	user.setUserId(newUserId());

	std::string login = "";
	do
	{
		std::cout << "Podaj login: ";
		getline(std::cin, login);
		user.setLogin(login);
	} while (isLoginTaken(user.getLogin()));

	std::cout << "Podaj haslo: ";
	std::string password = "";
	getline(std::cin, password);
	user.setPassword(password);

	std::cout << "Podaj imie: ";
	std::string name = "";
	getline(std::cin, name);
	name = HelperClass::convertStringToSentenceCase(name);
	user.setName(name);

	std::cout << "Podaj nazwisko: ";
	std::string surname = "";
	getline(std::cin, surname);
	surname = HelperClass::convertStringToSentenceCase(surname);
	user.setSurname(surname);

	return user;
}

void UserManager::registerUser()
{
	User user = provideNewUserLoginCredentials();

	users.push_back(user);
	userFile.saveAllUsersToFile(users);

	std::cout << std::endl << "Konto zalozono pomyslnie" << std::endl;
	HelperClass::pauseProgram();
}

void UserManager::logUserIn()
{
	std::string login = "", password = "";

	std::cout << std::endl << "Podaj login: ";
	getline(std::cin, login);

	std::vector <User>::iterator itr = users.begin(), end = users.end();
	while (itr != end)
	{
		if (itr->getLogin() == login)
		{
			for (int attempts = 3; attempts > 0; attempts--)
			{
				std::cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
				getline(std::cin, password);

				if (itr->getPassword() == password)
				{
					std::cout << std::endl << "Zalogowales sie." << std::endl;
					loggedUserId = itr->getUserId();
					HelperClass::pauseProgram();
					return;
				}
			}
			std::cout << "Wprowadzono 3 razy bledne haslo." << std::endl;
			loggedUserId = 0;
			HelperClass::pauseProgram();
			return;
		}
		itr++;
	}
	std::cout << "Nie ma uzytkownika z takim loginem" << std::endl;
	loggedUserId = 0;
	HelperClass::pauseProgram();
}

void UserManager::changeUserPassword()
{
	if (loggedUserId == 0)
		return;
	std::string newPassword = "";
	std::cout << "Podaj nowe haslo: ";
	getline(std::cin, newPassword);

	for (std::vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		if (itr->getUserId() == loggedUserId)
		{
			itr->setPassword(newPassword);
			std::cout << "Haslo zostalo zmienione." << std::endl;
			//userFile.updateUserInFile(*itr);
			HelperClass::pauseProgram();
		}
	}
}

void UserManager::logUserOut()
{
	loggedUserId = 0;
	std::cout << "Nastapilo wylogowanie uzytkownika" << std::endl;
}

int UserManager::getLoggedUserId()
{
	return loggedUserId;
}

bool UserManager::isUserLoggedIn()
{
	if (loggedUserId > 0)
		return true;
	else
		return false;
}

UserManager::~UserManager()
{
}
