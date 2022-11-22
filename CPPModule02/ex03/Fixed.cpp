#include "Fixed.hpp"

Fixed::Fixed()
{
	this->raw = 0;
	// std::cout << "Fixed Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Fixed Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
	// std::cout << "Fixed Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int val)
{
	// std::cout << "Fixed Int constructor called" << std::endl;
	this->raw = val * (1 << this->bit);
}

Fixed::Fixed(const float val)
{
	// std::cout << "Fixed Float constructor called" << std::endl;
	this->raw = roundf(val * (float)(1 << this->bit));
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	// std::cout << "Fixed Copy assignment operator called" << std::endl;
	this->raw = ref.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& cs)
{
	os << cs.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const
{
	return (this->raw);
}

void	Fixed::setRawBits(int const num)
{
	// std::cout << "Fixed setRawBits called" << std::endl;
	this->raw = num;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->raw / (float)(1 << this->bit));
}

int	Fixed::toInt(void) const
{
	return (this->raw / (1 << this->bit));
}

/*
 *  ex02 operator overloads ->
 */

bool	Fixed::operator<(const Fixed& ref)
{
	return (this->getRawBits() < ref.getRawBits() ? true : false);
}

bool	Fixed::operator>(const Fixed& ref)
{
	return (this->getRawBits() > ref.getRawBits() ? true : false);
}

bool	Fixed::operator>=(const Fixed& ref)
{
	return (this->getRawBits() >= ref.getRawBits() ? true : false);
}

bool	Fixed::operator<=(const Fixed& ref)
{
	return (this->getRawBits() <= ref.getRawBits() ? true : false);
}

bool	Fixed::operator==(const Fixed& ref)
{
	return (this->getRawBits() == ref.getRawBits() ? true : false);
}

bool	Fixed::operator!=(const Fixed& ref)
{
	return (this->getRawBits() != ref.getRawBits() ? true : false);
}

Fixed	Fixed::operator+(const Fixed& ref)
{
	return (this->toFloat() + ref.toFloat());
}

Fixed	Fixed::operator-(const Fixed& ref)
{
	return ((this->toFloat() - ref.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& ref)
{
	return (this->toFloat() * ref.toFloat());
}

Fixed	Fixed::operator/(const Fixed& ref)
{
	return (this->toFloat() / ref.toFloat());
}

Fixed& Fixed::operator++(void)
{
	this->raw++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->raw--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

/*
 *  ex02 operator overloads <-
 */

//*****************------
//min max functions

const	Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a: b;
}

const	Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a: b;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a: b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a: b;
}