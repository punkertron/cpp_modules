#include "iter.hpp"
#include <iostream>

template <typename T>
void int_incr(T &a) { a *= 5; }


/*check*/
class Awesome
{
	public:
		Awesome( void ) : _n(42) { return; }
		int	get( void ) const { return this->_n; }
	private:
		int	_n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }


/*mine*/
template <typename T>
class Foo
{
private:
	T n_val;

public:
	Foo(T i): n_val(i) {};
	T getVal() const { return n_val; }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, Foo<T> a)
{
	out << a.getVal();
	return (out);
}

template <typename T>
void print( T & x) { std::cout << x << std::endl; }


int main(void)
{
	int arr[3] = {1, 2, 3};
	std::cout << "arr: ";
	for (int i = 0; i < 3; i++) {std::cout << arr[i] << " ";}
	iter(arr, 3, int_incr);

	std::cout << std::endl;
	std::cout << "arr after ITER (*5): ";
	for (int i = 0; i < 3; i++) {std::cout << arr[i] << " ";}
	std::cout << std::endl;

	std::cout << "------------------" << std::endl;

	
	std::string s1 = "Hello", s2 = "It's", s3 = "Me";
	Foo<std::string> foo_arr[3] = {s1, s2, s3};

	iter(foo_arr, 3, print);

	std::cout << "------------------" << std::endl;

	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );


	return (0);
}
