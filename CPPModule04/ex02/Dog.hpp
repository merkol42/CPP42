#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include <iostream>

class Dog: public Animal
{
private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog& rhs);
	~Dog();

	Dog&	operator=(const Dog& rhs);

	Brain& getBrain(void) const;
	std::string	getType(void) const;
	void	makeSound(void) const;
};

#endif