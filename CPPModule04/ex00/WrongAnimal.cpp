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
	this->type = rhs.type;
	return (*this);
}

// std::string	WrongAnimal::getType(void) const
// {
// 	return (this->type);
// }

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimall!" << std::endl;
}