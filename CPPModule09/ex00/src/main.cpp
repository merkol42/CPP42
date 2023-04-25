#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: [" << argv[0] << " <filename>]" << std::endl;
		return (1);
	}

	std::ifstream inputFile(argv[1]);
	if (inputFile.is_open() == false)
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return (1);
	}
	
	BitcoinExchange	exchange("data.csv");
	std::string	line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		float value;
		if (std::getline(ss, date, '|') && ss >> value)
		{
			date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
			date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
			try
			{
				float exchangeRate = exchange.getRate(date, value);
				std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
	}
	return (0);
}