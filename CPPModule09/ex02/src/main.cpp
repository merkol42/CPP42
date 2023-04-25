#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "[Error]: no sequence provided" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe input(argc, argv);
		input.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}