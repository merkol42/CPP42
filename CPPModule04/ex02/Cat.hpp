#include "AAnimal.hpp"

class Cat: public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat& rhs);
	~Cat();

	Cat&	operator=(const Cat& rhs);

	Brain&	getBrain(void) const;
	std::string	getType(void) const;
	void		makeSound(void) const;
};