#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include "Array.hpp"

template<typename T>
class Array
{
private:
	T				*t;
	unsigned int	n;
public:
	Array();
	Array(unsigned int _n);
	Array(const Array& ref);
	~Array();

	Array&	operator=(const Array& ref);
	T&	operator[](int index);

	T	*getT() const;
	unsigned int	size() const;
};

#endif