#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& rhs);
	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap& rhs);

	std::string getName() const;
	
	void	whoAmI(void);
};

#endif