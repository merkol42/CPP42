#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():name("DiamondTrap")
{
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
	this->hit_points = 100;
	this->energy_point = 50;
	this->attack_damage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Desstructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name):ClapTrap(_name + "_clap_name")
{
	std::cout << "DiamondTrap String Constructor Called" << std::endl;
	this->name = _name;
	this->hit_points = 100;
	this->energy_point = 50;
	this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) :ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs)
{
	std::cout << "DiamondTrap Coppy Constructor Called" << std::endl;
	*this = rhs;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_point = rhs.energy_point;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

std::string DiamondTrap::getName() const
{
	return (this->name);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
	std::cout <<"DiamondTrap name: "<< this->name << std::endl;
}