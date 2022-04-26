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
	Point(const Point &a);
	const Point& operator=(const Point &a);

	void	print_point(void) const;
};

#endif