#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
// #include <unordered_map> since c++11 fastest one
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdint.h>

class BitcoinExchange
{
private:
	// std::unordered_map<std::string, float>	_data;
	std::map<std::string, float>	_data;
	std::fstream					_file;
	float							_rate;
public:
	BitcoinExchange();
	BitcoinExchange(const std::string& database);
	BitcoinExchange(const BitcoinExchange& cpy);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& rhs);

	float				getRate(const std::string &date, float val) const;

private:
	bool				isValidDate(const std::string& date) const;

protected:
	class invalidValueException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: not a positive number.");
			}
	};

	class invalidValueMaxException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: too large a number.");
			}
	};

	class invalidArgumentException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: Invalid Argument!");
			}
	};

	class invalidDateException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: bad input!");
			}
	};
};



#endif