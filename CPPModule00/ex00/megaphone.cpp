#include <iostream>

int	main(int ac, char **av)
{
	int	j;

	j = 0;
	if (ac > 1)
	{
		while (av[++j])
		{
			for (int i = 0; av[j][i] != '\0'; i++)
					std::cout << (char)toupper(av[j][i]);
			if (av[j + 1])
				std::cout << ' ';
		}
		std::cout << std::endl;
		return (0);
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (1);
}