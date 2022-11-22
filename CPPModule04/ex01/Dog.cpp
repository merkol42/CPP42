#include "Dog.hpp"

Dog::Dog(): brain(new Brain)
{
	std::cout << "Dog Default Constructor Called!" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& rhs) : Animal(), brain(new Brain)
{
	std::cout << "Dog Coppy Constructor Called!" << std::endl;
	*this = rhs;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor Called!" << std::endl;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		*(this->brain) = *(rhs.brain);
	}
	std::cout << "Dog Coppy Assignment Operator Called!" << std::endl;
	return (*this);
}

std::string	Dog::getType(void) const
{
	return (this->type);
}

Brain& Dog::getBrain(void) const
{
	return (*this->brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "Hrrrrrrrrrrrrrrrr!" << std::endl;
}