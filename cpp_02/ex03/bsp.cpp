#include "Point.hpp"
#include <iostream>

static float sign (Point p1, Point p2, Point p3)
{
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool b1, b2, b3;

    b1 = sign(point, a, b) <= 0.0f;
    b2 = sign(point, b, c) <= 0.0f;
    b3 = sign(point, c, a) <= 0.0f;

	//std::cout<< sign(point, a, b) << "|" << sign(point, b, c) << "|" << sign(point, c, a) << std::endl;

    return ((b1 == b2) && (b2 == b3));
}
