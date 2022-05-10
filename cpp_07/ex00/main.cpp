#include "whatever.hpp"
#include <iostream>

/*
class Foo
{
private:
	int m_number;

public:
	Foo(int a): m_number(a){};
	int	getNum() const {return m_number;}
	Foo& operator=(Foo const &a) { m_number = a.m_number; return *this; }
	bool operator>(Foo const &a) { return m_number > a.m_number;}
};

std::ostream& operator<<(std::ostream &out, const Foo &a)
{
	out << a.getNum();
	return (out);
}

int main(void)
{
	Foo a(20), b(40);

	std::cout << max(a, b) << std::endl;
	swap(a, b);
	std::cout << a.getNum() << std::endl;

	return (0);
}
*/

/*
int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
*/



int main(void)
{
	int a = 3, b = 5;
	double c = 4.6, d = 5.3;

	std::cout << "INT: a = " << a << " | b = " << b << std::endl;
	swap(a, b);
	std::cout << "INT after SWAP: a = " << a << " | b = " << b << std::endl;

	std::cout << "DOUBLE: c = " << c << " | d = " << d << std::endl;
	swap(c, d);
	std::cout << "DOUBLE after SWAP: c = " << c << " | d = " << d << std::endl;
	
	float f1 = 4.2, f2 = 4.2;

	std::cout << "min float = " << min(f1, f2) << std::endl;
	
	std::cout << "max int = " << max(a, b) << std::endl;
	std::cout << "max double = " << max(c, d) << std::endl;
	
	return (0);
}
