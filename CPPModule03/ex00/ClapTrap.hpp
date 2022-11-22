#ifndef _CLAP_TRAP_H
# define _CLAP_TRAP_H

#include <iostream>

class ClapTrap
{
private:
	std::string	name;
	int	hit_points;
	int	energy_point;
	int	attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string _name);
	ClapTrap(const ClapTrap& rhs);
	ClapTrap&	operator=(const ClapTrap& rhs);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
#endif