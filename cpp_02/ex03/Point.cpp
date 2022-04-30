#include "Point.hpp"
#include "iostream"

Point::Point(): x(0), y(0) {};

Point::~Point() {};

Point::Point(const Fixed a, const Fixed b): x(a), y(b) {}

Point::Point(const float a, const float b): x(a), y(b) {}

Point::Point(const Point &a): x(a.x), y(a.y) {};

const Point& Point::operator=(const Point &a)
{
	new (this) Point(a);
	return (*this);
}

void	Point::print_point(void) const
{
	std::cout << "x point: " << x << std::endl;
	std::cout << "y point: " << y << std::endl;
}

float	Point::getY() const
{
	return (this->x.toFloat());
}
float	Point::getX() const
{
	return (this->y.toFloat());
}
