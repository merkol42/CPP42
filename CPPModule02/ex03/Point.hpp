#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point();
	Point(const float inputx, const float inputy);
	Point(const Point& cpy);
	~Point();

	Point&	operator=(const Point& rvl);
	Fixed	getX() const;
	Fixed	getY() const;
};

bool	bsp(Point& A, Point& B, Point& C, Point& Pnt);

#endif