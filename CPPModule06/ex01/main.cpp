#include <iostream>
#include <iomanip>
#include <stdint.h>
#include "Data.hpp"

uintptr_t	serialize(Data* ptr)
{
	return	(reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return	(reinterpret_cast<Data *>(raw));
}

int	main( void )
{
	struct Data data1;

	data1.val = 42;

	uintptr_t	test = serialize(&data1);

	struct Data	*data2 = deserialize(test);

	std::cout << "--ADRESS COMPARE--" << std::endl;
	std::cout << "Data1 address: "<< &data1 << std::endl;
	std::cout << "Data2 address: "<< data2 << std::endl;
	std::cout << std::endl;

	std::cout << "--VALUE COMPARE--" << std::endl;
	std::cout << "Data1 value: " << data1.val << std::endl;
	std::cout << "Data2 value: " << data2->val << std::endl;
	data2->val = 52;
	std::cout << "Data2 uptade: " << data2->val << std::endl;
	return (0);
}