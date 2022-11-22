#include "Point.hpp"

/**
 * @brief Check if a point lies inside a triangle
 * 
 * @param A Corner points A(x,y)
 * @param B Corner points B(x,y)
 * @param C Corner points C(x,y)
 * @param P The point we are evaluating (x,y)
 * @return true if inside | 
 * @return false if outside
 */
bool	bsp(Point& A, Point& B, Point& C, Point& P)
{
	Fixed	divide = ((B.getY() - A.getY())
		* (C.getX() - A.getX()) - (B.getX() - A.getX())
		*(C.getY() - A.getY()));

	Fixed	w1 = (A.getX() * (C.getY() - A.getY()) + (P.getY()
		- A.getY()) * (C.getX() - A.getX()) - P.getX()
		* (C.getY() - A.getY())) / divide ;

	Fixed	w2 = (P.getY() - A.getY() - w1 * (B.getY() - A.getY()))
		/ (C.getY() - A.getY());

	if (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1)
		return (true);
	else
		return (false);
}