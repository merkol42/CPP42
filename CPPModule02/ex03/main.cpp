#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point A(1, 1);
	Point B(2, 5);
	Point C(5, 4);
	Point Pnt(2, 5);

	if (bsp(A,B,C,Pnt) == true)
		std::cout << "Inside" << std::endl;
	else
		std::cout << "Outside" << std::endl;
	return 0;
}