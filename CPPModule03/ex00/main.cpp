#include "ClapTrap.hpp"

int	main()
{
	ClapTrap A("Bilbo Bagggins");
	ClapTrap B("Gandalf");

	for (size_t i = 0; i < 12; i++)
	{
		A.takeDamage(5);
	}
}