#pragma once
#include <iostream>
#include <vector>
#include "HelperClass.h"
#include "Markup.h"
#include "User.h"


class UserFile
{
	const std::string usersFileName;
public:
	UserFile(std::string);
	void saveAllUsersToFile(std::vector<User>);
	std::vector <User> loadUsersFromFile();
	//void updateUserInFile(User);
	~UserFile();
};

