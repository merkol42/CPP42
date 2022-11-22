#include "AAnimal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default Constructor Called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor Called!" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	std::cout << "Animal Coppy Constructor Called!" << std::endl; 
	*this = rhs;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	this->type = rhs.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
}
