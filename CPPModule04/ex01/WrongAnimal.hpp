#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& rhs);
	~WrongAnimal();

	WrongAnimal&	operator=(const WrongAnimal& rhs);

	void	makeSound(void) const;
};

#endif