#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	const int count = 4;
	Animal	*animals[count];

	for (size_t i = 0; i < count; i++)
	{
		if (i < count / 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}
	std::cout << "-----------------------------\n";
	for (size_t i = 0; i < count; i++)
	{
		animals[i]->makeSound();
		std::cout << "-----------------------------\n";
		delete animals[i];
	}

	// Cat	*dog = new Cat();
	// Cat	*othr = new Cat();

	// *dog = *othr;

	// std::cout << &dog->getBrain() << "\n" << &othr->getBrain() << std::endl;
	// delete dog;
	// delete othr;
	// system("leaks deep_coppies");
}