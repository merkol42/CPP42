#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap A("Mete");
	std::cout << "-----------------\n";
	FragTrap B;
	std::cout << B;
	B = A;
	std::cout << A;
	std::cout << B;
	A.takeDamage(10);
	A.highFivesGuys();
	std::cout << A;
	A.takeDamage(20);
	std::cout << A;

	std::cout << "-----------------\n";

	// FragTrap *B = new FragTrap("Hulk");
	// ClapTrap *z = B;
	// std::cout << *B;
	// B->takeDamage(10);
	// B->highFivesGuys();
	// std::cout << *B;
	// B->takeDamage(20);
	// std::cout << *B;
	// delete z;

	// ClapTrap *B = new FragTrap("Corvus Glave");
	// ClapTrap *z = B;
	// std::cout << "-----------------\n";
	// B->takeDamage(10);
	// B->takeDamage(20);
	// std::cout << *z;
	// std::cout << *B;
	// delete z;
}