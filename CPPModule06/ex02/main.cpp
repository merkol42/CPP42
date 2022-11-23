#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	int random = (std::rand() % 3);
	A	*typeA;
	B	*typeB;
	C	*typeC;
	switch (random)
	{
		case (0):
			typeA = new A;
			std::cout << "Random A created" << std::endl;
			return (static_cast<Base *>(typeA));
			break ;
		case (1):
			typeB = new B;
			std::cout << "Random B created" << std::endl;
			return (static_cast<Base *>(typeB));
			break ;
		case (2):
			typeC = new C;
			std::cout << "Random C created" << std::endl;
			return (static_cast<Base *>(typeC));
			break ;
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}


void identify(Base& p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{
		std::cout << "Not A" << std::endl;
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{
		std::cout << "Not B" << std::endl;
	}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc)
	{
	}
}

int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "--GENERATE()--" << std::endl;
	Base *rand1 = generate();
	Base *rand2 = generate();
	Base *rand3 = generate();
	Base *rand4 = generate();
	std::cout << std::endl;

	Base &rand1_ref = *rand1;
	Base &rand2_ref = *rand2;
	Base &rand3_ref = *rand3;
	Base &rand4_ref = *rand4;

	std::cout << "--IDENTIFY WITH ADRESS--" << std::endl;
	identify(rand1);
	identify(rand2);
	identify(rand3);
	identify(rand4);
	std::cout << std::endl;

	std::cout << "--IDENTIFY WITH REFERENCE--" << std::endl;
	identify(rand1_ref);
	identify(rand2_ref);
	identify(rand3_ref);
	identify(rand4_ref);
	std::cout << std::endl;

	std::cout << "--DESTRUCTORS--" << std::endl;
	delete rand1;
	delete rand2;
	delete rand3;
	delete rand4;
	return (0);
}