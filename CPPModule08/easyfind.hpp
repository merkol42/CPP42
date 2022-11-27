#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <list>
# include <iterator>
# include <vector>
# include <array>

// Find the the first occurrence of the second parameter in the first parameter
template< typename T >
int easyfind(T const& t, int n)
{
	typename T::const_iterator end = t.end();

	/*
		Finds the element in the given range of numbers. 
		Returns an iterator to the first element in the range [first,last) that compares equal to val.
		If no such element is found, the function returns last.
	*/
	typename T::const_iterator it = std::find(t.begin(), end, n);

	return (it == end ? throw(std::out_of_range("Element not found in given range")) : *it);
}


#endif