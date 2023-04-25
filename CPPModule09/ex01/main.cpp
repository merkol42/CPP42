#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	rpn;
	std::string arg;
	
	
	if (argc == 1)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
		return (1);
	}
	if (argc > 2)
	{
		for (size_t i = 1; *(argv + i); i++)
			arg += *(argv + i);
	}
	else
		arg = argv[1];
	try
	{
		rpn.reversePolishNotation(arg);
		std::cout << rpn << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}