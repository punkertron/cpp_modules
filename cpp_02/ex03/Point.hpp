#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const	x;
	Fixed const	y;

public:
	Point();
	~Point();
	Point(const Fixed a, const Fixed b);
	Point(const float a, const float b);
	Point(const Point &a);
	const Point& operator=(const Point &a);

	void	print_point(void) const;

	float	getY() const;
	float	getX() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif