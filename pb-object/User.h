#pragma once
#include <iostream>

class User
{
	int userId;
	std::string login, password, name, surname;
public:
	User();

	int getUserId();
	std::string getLogin();
	std::string getPassword();
	std::string getName();
	std::string getSurname();

	void setUserId(int);
	void setLogin(std::string);
	void setPassword(std::string);
	void setName(std::string);
	void setSurname(std::string);

	~User();
};

