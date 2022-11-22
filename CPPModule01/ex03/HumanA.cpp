#include "HumanA.hpp"

HumanA::HumanA()
{
}

HumanA::~HumanA()
{
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->name = name;
	this->gun = &weapon;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->gun->getType() << std::endl;
}