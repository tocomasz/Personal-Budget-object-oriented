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
}

UserFile::~UserFile()
{
}
