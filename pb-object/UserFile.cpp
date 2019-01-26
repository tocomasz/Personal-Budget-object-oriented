#include "UserFile.h"



UserFile::UserFile()
{
}
/*
std::vector <User> UserFile::loadUsersFromFile()
{
	std::vector <User> users;
	std::string line;
	User user;
	fstream textFile;
	textFile.open(usersFileName.c_str(), ios::in);
	if (textFile.good() == true)
	{
		while (getline(textFile, line))
		{
			user = divideLineWithSeparatorsIntoUserData(line);
			users.push_back(user);
		}
		textFile.close();
	}
	return users;
}
*/

void UserFile::saveUserToFile(User user)
{
	CMarkup xml;
	xml.AddElem("USERS");
	xml.IntoElem();
	xml.AddElem("USER");
	xml.IntoElem();
	xml.AddElem("USERID", user.getUserId());
	xml.AddElem("LOGIN", user.getLogin());
	xml.AddElem("PASSWORD", user.getPassword());
	xml.AddElem("NAME", user.getName());
	xml.AddElem("SURNAME", user.getSurname());
	xml.Save("sample.xml");

	/*
	std::string line = "";
	fstream textFile;
	textFile.open(usersFileName.c_str(), ios::app);

	if (textFile.good() == true)
	{
		line = addSeparatingLinesToUserData(user);

		if (HelperClass::isFileEmpty(usersFileName) == true)
		{
			textFile << line;
		}
		else
		{
			textFile << std::endl << line;
		}
		textFile.close();
	}
	else
		std::cout << "Nie udalo sie otworzyc pliku " << usersFileName << " i zapisac w nim danych." << endl;
	*/
}

/*
void UserFile::updateUserInFile(User user)
{
	fstream textFile, temp;
	textFile.open(usersFileName.c_str(), ios::in);
	temp.open("temp.txt", ios::out);
	if (textFile.good() && temp.good())
	{
		bool isFirstLine = true;
		string loadedLine = "";
		while (getline(textFile, loadedLine))
		{
			if (!isFirstLine)
				temp << endl;
			if (loadedLine[0] - '0' == user.getId())
			{
				temp << user.getId() << "|";
				temp << user.getLogin() << "|";
				temp << user.getPassword() << "|";
				isFirstLine = false;
				continue;
			}
			temp << loadedLine;
			isFirstLine = false;
		}
	}
	textFile.close();
	textFile.clear();
	temp.close();
	temp.clear();
	remove(usersFileName.c_str());
	rename("temp.txt", usersFileName.c_str());
}
*/

UserFile::~UserFile()
{
}
