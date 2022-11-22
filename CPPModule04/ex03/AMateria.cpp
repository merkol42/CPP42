#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor Called" << std::endl;
}

AMateria::AMateria(AMateria const &rhs) :type(rhs.type)
{
	std::cout << "AMaterial Copy Constructor Called" << std::endl;
	*this = rhs;
}

AMateria::AMateria(std::string const &_type) :type(_type)
{
	std::cout << "AMateria String Constructor Called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	(void)rhs;
	std::cout << "AMateria Assignment Operator Called" << std::endl;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria abstractly use " << target.getName() << std::endl;
}