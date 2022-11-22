#ifndef _FRAG_TRAP_HPP
# define _FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap& rhs);
	FragTrap&	operator=(const FragTrap& rhs);
	~FragTrap();

	void	highFivesGuys();
};

#endif