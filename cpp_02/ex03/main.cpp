#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point point1;

	Point point2;
	Point point3(Fixed(3), Fixed(4));

	point2 = point1;

	point1.print_point();
	point2.print_point();

	point2 = point3;
	point2.print_point();
	return (0);
}
