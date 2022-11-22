#ifndef _SCAV_TRAP_H
# define _SCAV_TRAP_H

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
private:
	bool	guard_mode;
public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& rhs);
	ScavTrap&	operator=(const ScavTrap& rhs);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();
	void	changeGuardMod(bool a);
	void	takeDamage(unsigned int amount);
};

#endif