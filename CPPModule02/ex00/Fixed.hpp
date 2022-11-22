#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	raw;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(const Fixed& cpy);
	Fixed& operator=(const Fixed& ref);
	~Fixed();

	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif