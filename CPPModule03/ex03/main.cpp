#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap A("Hulk");
	DiamondTrap B("mete");
	std::cout << "-------------------\n";
	B.whoAmI();
	std::cout << B;
	B.attack(A.getName());
	B.guardGate();
	B.beRepaired(10);
	B.highFivesGuys();
	// B.highFivesGuys();
	// std::cout << B << std::endl;
	// delete B;
}