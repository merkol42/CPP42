#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	Weapon		*gun;
	std::string	name;
public:
	HumanB();
	~HumanB();
	HumanB(std::string name);

	void	setWeapon(Weapon &wp);
	void	attack();
};

#endif