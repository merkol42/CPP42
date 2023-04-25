#include "BitcoinExchange.hpp"
#include <stdlib.h>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& database)
{
	std::ifstream	file(database.c_str());
	if (!file.is_open())
		throw invalidArgumentException();
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		float				price;
		
		if (std::getline(ss, date, ',') && ss >> price)
		{
			date.erase(0, date.find_first_not_of(" \t\r\n\v"));
			date.erase(date.find_last_not_of(" \t\r\n\v") + 1);
			if (!this->isValidDate(date))
				throw invalidDateException();
			_data[date] = price;
		}
	}
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
	*this = cpy;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		this->_data = rhs._data;
	return (*this);
}

float	BitcoinExchange::getRate(const std::string& date, float val) const
{
	if (val < 0)
		throw invalidValueException();
	if (val > 2.14748e+09)
		throw invalidValueMaxException();
	if (!isValidDate(date))
		throw invalidDateException();
	
	std::map<std::string, float>::const_iterator	it = _data.find(date);
	if (it == _data.end())
	{
		it = _data.upper_bound(date);
		if (it == _data.begin())
			throw invalidArgumentException();
		if (it == _data.end())
			--it;
	}
	return (it->second);
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	int		year;
	int		month;
	int		day;
	char	sep;

	std::istringstream	iss(date);

	iss >> year >> sep >> month >> sep >> day;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return (false);
		}
		else if (day > 28)
			return (false);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30)
			return (false);
	return (true);
}