#include "Point.hpp"

Point::Point() :x(0), y(0)
{
	// std::cout << "Point Default constructor" << std::endl;
}

Point::Point(const float inputx, const float inputy) :x(inputx), y(inputy)
{
	// std::cout << "Point Float constructor" << std::endl;
}

Point::Point(const Point& cpy) :x(cpy.x), y(cpy.y)
{
	// std::cout << "Point Copy constructor" << std::endl;
}

Point&	Point::operator=(const Point& rvl)
{
	// std::cout << "Point cpy assign called" << std::endl;
	if (this == &rvl)
		return (*this);
	this->getX().setRawBits(rvl.x.getRawBits());
	this->getY().setRawBits(rvl.y.getRawBits());
	return (*this);
}

Point::~Point()
{
	// std::cout << "Point Destructor called" << std::endl;
}

Fixed	Point::getX() const
{
	// return ((Fixed *)&this->x);
	return (this->x);
}
Fixed	Point::getY() const
{
	return (this->y);
}