#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template< typename T>
void iter(T *array, int array_length, void f(T const &ref))
{
	for(int i = 0; i < array_length; i++)
		f(array[i]);
	std::cout << std::endl;
}

template< typename T>
void	print_value(T const &t)
{
	std::cout << t << " | ";
}

#endif