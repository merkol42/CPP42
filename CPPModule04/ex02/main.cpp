#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void	loop()
{
	Dog	a;
	Cat	b;
	Animal *c = new Cat;
	a.makeSound();
	b.makeSound();
	c->makeSound();
	delete c;
}

int	main(void)
{
	loop();
}