#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap A("Mete");
	std::cout << A;
	A.takeDamage(10);
	A.changeGuardMod(true);
	std::cout << A;
	A.takeDamage(20);
	A.beRepaired(5);
	A.attack("sa");
	std::cout << A;

	std::cout << "-----------------\n";

	// ScavTrap *A = new ScavTrap("Mete");
	// ClapTrap *x = A;
	// // std::cout << *x;
	// std::cout << *A;
	// A->takeDamage(10);
	// A->changeGuardMod(true);
	// std::cout << *A;
	// A->takeDamage(20);
	// delete x;


	// ClapTrap *x = new ClapTrap("deneme");
	// x->attack("zaaaa");
	// delete x;

	// std::cout << "-----------------\n";

	// ClapTrap *A = new ScavTrap("mete");
	// A->attack("zaa");
	// delete A;
}