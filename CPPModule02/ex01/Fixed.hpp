#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	num;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(const Fixed& cpy);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();

	Fixed& operator=(const Fixed& ref);
	int		getRawBits(void) const;
	void	setRawBits(int const num);
	float	toFloat(void) const;
	int		toInt(void) const;
};

	std::ostream& operator<<(std::ostream& os, const Fixed& cs);
#endif