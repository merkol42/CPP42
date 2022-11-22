#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string _name)
{
	std::cout << "FragTrap String constructor called" << std::endl;
	this->name = _name;
	this->hit_points = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
}


FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap Coppy Constructor Called" << std::endl;
	*this = rhs;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap Coppy Assignment Constructor Called" << std::endl;
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_point = rhs.energy_point;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << this->getName() << ": HIGH FIVES GUYSSSSSSS!!!" << std::endl;
}