#include "HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::~HumanB()
{
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->gun = NULL;
}

void	HumanB::setWeapon(Weapon &wp)
{
	this->gun = &wp;
}

void	HumanB::attack()
{
	if (this->gun)
	{
		std::cout << this->name << " attacks with their ";
		std::cout << this->gun->getType() << std::endl;
	}
	else
		std::cout << "No Weapon!" << std::endl;
}