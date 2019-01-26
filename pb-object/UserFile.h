#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

class UserFile
{
	const std::string usersFileName;
public:
	UserFile();
	void saveUserToFile(User);
	//std::vector <User> loadUsersFromFile();
	//void updateUserInFile(User);
	~UserFile();
};

