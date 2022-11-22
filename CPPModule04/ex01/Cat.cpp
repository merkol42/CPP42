#include "Cat.hpp"

Cat::Cat() : brain(new Brain)
{
	std::cout << "Cat Default Constructor Called!" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& rhs) : Animal(), brain(new Brain)
{
	std::cout << "Cat Coppy Constructor Called!" << std::endl;
	*this = rhs;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor Called!" << std::endl;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		*(this->brain) = *(rhs.brain);
	}
	std::cout << "Cat Coppy Assignment Operator Called!" << std::endl;
	return (*this);
}

Brain& Cat::getBrain(void) const
{
	return (*this->brain);
}

std::string	Cat::getType(void) const
{
	return (this->type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meowwwwwwwww!" << std::endl;
}