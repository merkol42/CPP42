#include "Fixed.hpp"

Fixed::Fixed()
{
	this->num = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->num = val * (1 << this->bit);
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->num = roundf(val * (1 << this->bit));
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = ref.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& cs)
{
	os << cs.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->num);
}

void	Fixed::setRawBits(int const num)
{
	std::cout << "setRawBits called" << std::endl;
	this->num = num;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->num / (float)(1 << this->bit));
}

int	Fixed::toInt(void) const
{
	return (this->num / (1 << this->bit));
}