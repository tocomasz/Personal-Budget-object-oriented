#include "DateManager.h"

DateManager::DateManager()
{
}

Date DateManager::pickDateMenu()
{	
	while (true)
	{
		std::cout << "1. Dzisiaj" << std::endl;
		std::cout << "2. Wybierz inna date" << std::endl;
		char ch = HelperClass::loadCharacter();
		std::string dateAsString = "";
		switch (ch)
		{
		case '1':
			return getCurrentDate();
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
	std::cout << "Wprowadz date w formacie RRRR-MM-DD, znajdujaca sie w przedziale od 2000-1-1 do ostatniego dnia biezacego miesiaca: " << std::endl;
	std::string dateAsString = HelperClass::loadLine();
	return dateAsString;
}

Date DateManager::getCurrentDate()
{
	time_t t = time(0);
	tm now;
	auto ptr = &now;
	time(&t);
	localtime_s(ptr, &t);
	return Date((now.tm_year + 1900), (now.tm_mon + 1), (now.tm_mday));
}

bool DateManager::isEarlierOrEqual(Date first, Date second)
{
	if (first.getYear() == second.getYear() && first.getMonth() == second.getMonth() && first.getDay() == second.getDay())
		return true;
	else
		return isEarlier(first, second);
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

Date DateManager::getFirstDayOfPreviousMonth()
{
	Date currentDate = getCurrentDate();
	int previousMonth = 0;
	int year = currentDate.getYear();
	if (currentDate.getMonth() == 1)
	{
		year--;
		previousMonth = 12;
	}
	else
		previousMonth = currentDate.getMonth() - 1;

	return Date(year, previousMonth, 1);
}

DateManager::~DateManager()
{
}
