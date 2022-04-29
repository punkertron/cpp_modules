#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	{
		Point point1(Fixed(3), Fixed(7));
		Point point2(Fixed(1), Fixed(8));
		Point point3(Fixed(3), Fixed(4));

		Point	test(Fixed(2), Fixed(2));
		if (bsp(point1, point2, point3, test) == false) //not in
			std::cout << "Success!" << std::endl;
		else
			std::cout << "Fail!" << std::endl;
	}
	{
		Point point1(Fixed(5), Fixed(0));
		Point point2(Fixed(1), Fixed(4));
		Point point3(Fixed(-1), Fixed(-2));

		Point	test(Fixed(2), Fixed(1));
		if (bsp(point1, point2, point3, test) == true) //in
			std::cout << "Success!" << std::endl;
		else
			std::cout << "Fail!" << std::endl;
	}
	{
		Point point1(Fixed(0), Fixed(0));
		Point point2(Fixed(0), Fixed(5));
		Point point3(Fixed(7), Fixed(0));

		Point	test(Fixed(0), Fixed(0));
		if (bsp(point1, point2, point3, test) == false) //border
			std::cout << "Success!" << std::endl;
		else
			std::cout << "Fail!" << std::endl;
	}


	/*point1.print_point();
	point2.print_point();

	point2 = point3;
	point2.print_point();
	*/
	return (0);
}
