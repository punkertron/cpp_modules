#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	
	
	/*test comparison*/
	std::cout << "test comparison:" << std::endl;
	a > b ? std::cout << "a > b - true" : std::cout << "a > b - false";
	std::cout << std::endl;
	a < b ? std::cout << "a < b - true" : std::cout << "a < b - false";
	std::cout << std::endl;
	b != d ? std::cout << "b != d - true" : std::cout << "b != d - false";
	std::cout << std::endl;
	b == d ? std::cout << "b == d - true" : std::cout << "b == d - false";
	std::cout << std::endl << std::endl;

	/* test arithmetic */
	std::cout << "test arithmetic:" << std::endl;
	std::cout << "b + c or 10 + 42.42 = " << b + c << std::endl;
	std::cout << "b - d + a or 10 - 10 + 1234.4321 = "
		<< b - d + a << std::endl;

	std::cout << "b * a or 10 * 1234.4321 = " << a * b << std::endl;
	std::cout << "c / b or 42.42 / 10 = " << c / b << std::endl;

	Fixed h = b + c; //10 + 42.42

	std::cout << "h = " << h << std::endl;


	return (0);
}
