#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal()
{
	std::cout << "WrongCat Coppy Constructor Called!" << std::endl; 
	*this = rhs;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat Coppy Assignment Operator Called!" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCatl!" << std::endl;
}