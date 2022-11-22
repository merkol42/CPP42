#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "Brain.hpp"
#include <string>
#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal& rhs);
	virtual ~Animal();

	Animal&	operator=(const Animal& rhs);

	virtual	std::string	getType(void) const;
	virtual	void	makeSound(void) const = 0;
};

#endif