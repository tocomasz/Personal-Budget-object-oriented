#include "DateManager.h"



DateManager::DateManager()
{
}

Date DateManager::pickDateMenu()
{	
	while (true)
	{
		std::cout << "Wybierz date przychodu/wydatku: " << std::endl;
		std::cout << "1. Dzisiaj" << std::endl;
		std::cout << "2. Wybierz inna date" << std::endl;
		char ch = HelperClass::loadCharacter();
		std::string dateAsString = "";
		switch (ch)
		{
		case '1':
			dateAsString = getCurrentDate();
			break;
		case '2':
			dateAsString = loadDate();
		}
		Date date(dateAsString);
		if (date.isDateValid())
			return date;
		else
		{
			std::cout << "Wprowadzono bledna date" << std::endl;
			HelperClass::pauseProgram();
			system("cls");
		}
	}
}

std::string DateManager::loadDate()
{
	std::cout << "Wprowadz date w formacie RRRR-MM-DD: " << std::endl;
	std::string dateAsString = HelperClass::loadLine();
	return dateAsString;
}

std::string DateManager::getCurrentDate()
{
	time_t t = time(0);
	tm now;
	auto ptr = &now;
	time(&t);
	localtime_s(ptr, &t);
	std::string currentDateAsString = HelperClass::intToString(now.tm_year + 1900) + '-' + HelperClass::intToString(now.tm_mon + 1) + '-' + HelperClass::intToString(now.tm_mday);
	return currentDateAsString;
}

bool DateManager::isEarlierOrEqual(Date first, Date second)
{
	if (second.getYear() < first.getYear())
		return false;
	else if (second.getYear() > first.getYear())
		return true;
	else
	{
		if (second.getMonth() > first.getMonth())
			return false;
		else if (second.getMonth() < first.getMonth())
			return true;
		else
		{
			if (second.getDay() > first.getDay())
				return true;
			else if (second.getDay() < first.getDay())
				return false;
			else
				return true;
		}
	}
}

bool DateManager::isEarlier(Date first, Date second)
{
	if (second.getYear() < first.getYear())
		return false;
	else if (second.getYear() > first.getYear())
		return true;
	else
	{
		if (second.getMonth() > first.getMonth())
			return false;
		else if (second.getMonth() < first.getMonth())
			return true;
		else
		{
			if (second.getDay() > first.getDay())
				return true;
			else if (second.getDay() < first.getDay())
				return false;
			else
				return false;
		}
	}
}

DateManager::~DateManager()
{
}
