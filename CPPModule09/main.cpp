#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: [" << argv[0] << " <filename>]" << std::endl;
		return (1);
	}

	BitcoinExchange	bc;
	std::cout << bc(argv[1]) << std::endl;
	return (0);
}