#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal Coppy Constructor Called!" << std::endl; 
	*this = rhs;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal Coppy Assignment Operator Called!" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimall!" << std::endl;
}