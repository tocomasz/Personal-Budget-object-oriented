#include "UserFile.h"



UserFile::UserFile(std::string USERSFILENAME)
	:usersFileName(USERSFILENAME)
{
}

std::vector <User> UserFile::loadUsersFromFile()
{
	std::vector <User> users;
	User user;
	CMarkup xml;
	xml.Load(usersFileName.c_str());

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("USER"))
	{
		xml.IntoElem();
		xml.FindElem("USERID");
		user.setUserId(HelperClass::stringToInt(xml.GetData()));
		xml.FindElem("LOGIN");
		user.setLogin(xml.GetData());
		xml.FindElem("PASSWORD");
		user.setPassword(xml.GetData());
		xml.FindElem("NAME");
		user.setName(xml.GetData());
		xml.FindElem("SURNAME");
		user.setSurname(xml.GetData());
		xml.OutOfElem();
		users.push_back(user);
	}
	return users;
}


void UserFile::saveAllUsersToFile(std::vector<User> users)
{
	CMarkup xml;
	xml.AddElem("USERS");
	xml.IntoElem();
	for (std::vector <User>::iterator itr = users.begin(), end = users.end(); itr != end; itr++)
	{
		xml.AddElem("USER");
		xml.IntoElem();
		xml.AddElem("USERID", itr->getUserId());
		xml.AddElem("LOGIN", itr->getLogin());
		xml.AddElem("PASSWORD", itr->getPassword());
		xml.AddElem("NAME", itr->getName());
		xml.AddElem("SURNAME", itr->getSurname());
		xml.OutOfElem();
	}

	xml.Save(usersFileName.c_str());

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
