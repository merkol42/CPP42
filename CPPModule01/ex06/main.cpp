#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./harlFilter [COMMAND]" << std::endl;
		return (0);
	}
	
	Harl haarl;

	haarl.complain(av[1]);
	return (0);
}