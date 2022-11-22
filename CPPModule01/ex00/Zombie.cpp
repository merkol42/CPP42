#include "Zombie.hpp"

Zombie::Zombie(std::string zname)
{
	this->name = zname;
}

Zombie::~Zombie()
{
	std::cout << this->name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	newZombie(std::string name)
{
	Zombie *braineater = new Zombie(name);
	return (braineater);
}

void	randomChump(std::string name)
{
	Zombie maneater(name);
	maneater.announce();
}