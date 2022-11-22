#include "Ice.hpp"

Ice::Ice() :AMateria("ice")
{
	std::cout << "Ice Default Constructor Called!" << std::endl;
}

Ice::Ice(const Ice& rhs) :AMateria()
{
	std::cout << "Ice Copy Constructor Called!" << std::endl;
	*this = rhs;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor Called!" << std::endl;
}

Ice&	Ice::operator=(const Ice& rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	std::cout << "Ice Assignment Operator Called!" << std::endl;
	return (*this);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice*	Ice::clone() const
{
	std::cout << "Ice Clone Called!" << std::endl;
	return (new Ice());
}