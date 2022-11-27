#include "easyfind.hpp"

// list / vector / array
// ------------------------------
// list stores data with double linked list
// vector vs list = vector regular array  (not linked list) , both are dynamic
// vector = only push_back , contiguous data store
// list = push_back and front(dbl linked list)
// array = fixed size


void	print_value(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	std::cout << "--LIST TEST--" << std::endl;
	std::list<int> lst;

	for (int i = 1; i <= 5; i++)
		lst.push_front(i);
	std::for_each(lst.begin(), lst.end(), print_value);
	std::cout << "easyfind():" << std::endl;
	std::cout << easyfind(lst, 3) << std::endl << std::endl;
	std::cout << "out of rane:" << std::endl;
	try
	{
		std::cout << easyfind(lst, -1) << std::endl << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "--VECTOR TEST--" << std::endl;
	std::vector<int> vector;

	for (int i = 1; i <= 5; i++)
		vector.push_back(i);

	std::for_each(vector.begin(), vector.end(), print_value);
	std::cout << std::endl;

	std::cout << "easyfind():" << std::endl;
	std::cout << easyfind(vector, 3) << std::endl << std::endl;
	std::cout << "out of rane:" << std::endl;
	try
	{
		std::cout << easyfind(vector, -1) << std::endl << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "--ARRAY TEST--" << std::endl;
	std::array<int, 5> array;

	for (int i = 1; i <= 5; i++)
		array[i - 1] = i;


	std::for_each(array.begin(), array.end(), print_value);
	std::cout << std::endl;

	std::cout << "easyfind():" << std::endl;
	std::cout << easyfind(array, 2) << std::endl << std::endl;
	std::cout << "out of rane:" << std::endl;
	try
	{
		std::cout << easyfind(array, -28) << std::endl << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return (0);
}