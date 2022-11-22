#include "ClapTrap.hpp"

ClapTrap::ClapTrap()	:hit_points(10), energy_point(10),attack_damage(0)
{
	std::cout << "ClapTrap Default constructur" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)	:hit_points(10), energy_point(10),attack_damage(0)
{
	std::cout << "ClapTrap String constructur" << std::endl;
	this->name = _name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructur" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << "ClapTrap Copy Constructur" << std::endl;
	*this = rhs;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "ClapTrap Copy Assignment Constructur" << std::endl;
	this->name = rhs.name;
	this->attack_damage = rhs.attack_damage;
	this->energy_point = rhs.energy_point;
	this->hit_points = rhs.hit_points;
	return (*this);
}


void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_point > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage \
				<< " points of damage!" << std::endl;
		this->energy_point--;
		if (this->energy_point < 0)
			this->energy_point = 0;
	}
	else
		std::cout << this->name << " I'm Done!" << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
		std::cout << this->name << " take " << amount << " damage" << std::endl;
		this->hit_points -= amount;
		if (this->hit_points < 0)
			this->hit_points = 0;
	}
	else
		std::cout << this->name << ": You can't damage the dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points > 0 && this->energy_point > 0)
	{
		std::cout << this->name << " repaired " << amount << " hit points" << std::endl;
		this->energy_point--;
		this->hit_points += amount;
		if (this->hit_points < 0)
			this->hit_points = 0;
	}
	else
		std::cout << this->name << " I'm Done!" << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (this->name);
}

int	ClapTrap::getEp() const
{
	return (this->energy_point);
}
int	ClapTrap::getHp() const
{
	return (this->hit_points);
}
int	ClapTrap::getAttck() const
{
	return (this->attack_damage);
}

std::ostream& operator<<(std::ostream& os, ClapTrap& ref)
{
	os	<< "Name\t\t:" << ref.getName() << std::endl
		<< "HitPoints\t:" << ref.getHp() << std::endl
		<< "EnergyPoint\t:" << ref.getEp() << std::endl
		<< "AttackDamage\t:" << ref.getAttck() << std::endl;
	return (os);
}