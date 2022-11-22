#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name)
{
	std::cout << "ScavTrap String Constructor called" << std::endl;
	this->name = _name;
	this->hit_points = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->guard_mode = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "ScavTrap Coppy Constructor Called" << std::endl;
	*this = rhs;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap Coppy Assignment Constructor Called" << std::endl;
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_point = rhs.energy_point;
	this->attack_damage = rhs.attack_damage;
	this->guard_mode = rhs.guard_mode;
	return (*this);
}

/*
	Methods
*/
void	ScavTrap::guardGate()
{
	if (this->guard_mode)
		std::cout << this->getName() << " activated Guard Mode" << std::endl;
	else
		std::cout << this->getName() << " not activated Guard Mode" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->guard_mode)
		std::cout << this->getName() << "'s Guard Mode active don't take any damage" << std::endl;
	else
		ClapTrap::takeDamage(amount);
}

void	ScavTrap::changeGuardMod(bool a)
{
	this->guard_mode = a;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_point > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->attack_damage \
				<< " points of damage!" << std::endl;
		this->energy_point--;
		if (this->energy_point < 0)
			this->energy_point = 0;
	}
	else
		std::cout << this->name << " I'm Done!" << std::endl; 
}
//Methods