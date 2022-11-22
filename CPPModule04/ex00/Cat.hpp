#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& rhs);
	~Cat();

	Cat&	operator=(const Cat& rhs);

	std::string	getType(void) const;
	void		makeSound(void) const;
};