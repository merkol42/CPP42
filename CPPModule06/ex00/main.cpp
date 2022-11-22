#include <iostream>
#include <iomanip>
#include "Converter.hpp"
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Argument Error!" << std::endl;
		return (0);
	}

	char		c;
	int			n;
	float		f;
	double		d;

	std::cout << std::fixed << std::setprecision(1);
	
	std::string	argument = argv[1];
	
	Converter	converter(argument);

	c = static_cast<char>(converter);
	n = static_cast<int>(converter);
	f = static_cast<float>(converter);
	d = static_cast<double>(converter);

	(void)c;
	(void)n;
	(void)f;
	(void)d;

	return (0);
}