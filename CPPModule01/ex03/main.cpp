#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("Hell Blade");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Long Spear");
		bob.attack();
	}
	{
		Weapon club = Weapon("Iron Breaker");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Long Spear");
		jim.attack();
	}
	return 0;
}