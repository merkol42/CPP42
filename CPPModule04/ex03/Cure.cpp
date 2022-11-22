#include "Cure.hpp"

Cure::Cure() :AMateria("cure")
{
	std::cout << "Cure Default Constructor Called!" << std::endl;
}

Cure::Cure(const Cure& rhs) :AMateria()
{
	std::cout << "Cure Copy Constructor Called!" << std::endl;
	*this = rhs;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor Called!" << std::endl;
}

Cure&	Cure::operator=(const Cure& rhs)
{
	if (this != &rhs)
		this->type = rhs.getType();
	std::cout << "Cure Assignment Operator Called!" << std::endl;
	return (*this);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure*	Cure::clone() const
{
	std::cout << "Cure Clone Called!" << std::endl;
	return (new Cure());
}