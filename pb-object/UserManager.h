#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "HelperClass.h"
#include "User.h"
#include "UserFile.h"

class UserManager
{
	std::vector<User> users;
	int loggedUserId;
	UserFile userFile;

	int newUserId();
	bool isLoginTaken(std::string);
	User provideNewUserLoginCredentials();
public:
	UserManager(std::string);
	void registerUser();
	void logUserIn();
	void changeUserPassword();
	void logUserOut();
	int getLoggedUserId();
	bool isUserLoggedIn();
	~UserManager();
};

