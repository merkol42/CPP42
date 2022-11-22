#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	Weapon		*gun;
	std::string	name;
public:
	HumanA();
	~HumanA();
	HumanA(std::string name, Weapon &weapon);

	void	attack();
};

#endif