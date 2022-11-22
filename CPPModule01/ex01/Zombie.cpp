#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << this->name << std::endl;
}

void	Zombie::setName(std::string zname)
{
	this->name = zname;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
		zombies[i].announce();
	}
	return (zombies);
}
