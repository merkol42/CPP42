#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	raw;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(const Fixed& cpy);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();

	Fixed&	operator=(const Fixed& ref);
	int		getRawBits(void) const;
	void	setRawBits(int const num);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator<(const Fixed& ref);
	bool	operator>(const Fixed& ref);
	bool	operator>=(const Fixed& ref);
	bool	operator<=(const Fixed& ref);
	bool	operator==(const Fixed& ref);
	bool	operator!=(const Fixed& ref);

	Fixed	operator+(const Fixed& ref);
	Fixed	operator-(const Fixed& ref);
	Fixed	operator*(const Fixed& ref);
	Fixed	operator/(const Fixed& ref);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static	const	Fixed&	min(const Fixed& a, const Fixed& b);
	static	Fixed&	min(Fixed& a, Fixed& b);
	static	const	Fixed&	max(const Fixed& a, const Fixed& b);
	static	Fixed&	max(Fixed&a, Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& cs);

#endif