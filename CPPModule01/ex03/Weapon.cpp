#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon(std::string input)
{
	this->type = input;
}

const	std::string& Weapon::getType()
{
	return ((const std::string&)this->type);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}