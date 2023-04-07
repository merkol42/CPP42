#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>

class BitcoinExchange
{
private:
	std::map<int, float>	data;
	std::fstream			file;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& cpy);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& rhs);

	float	operator()(std::string filename);
	std::map<int, float>	getMap();
};

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
	*this = cpy;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	this->data = rhs.data;
	return (*this);
}

float	BitcoinExchange::operator()(std::string filename)
{
	std::cout << filename << std::endl;
	return (0.42f);
}

#endif