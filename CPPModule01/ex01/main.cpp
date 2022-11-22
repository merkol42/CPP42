#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies = zombieHorde(10, "ZaaaaxD");
	delete[] zombies;
}