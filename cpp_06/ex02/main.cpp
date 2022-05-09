#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

int main(void)
{
	Base *ptr;

	ptr = generate();

	Base &ref = *ptr;
	std::cout << "ptr:" << std::endl;
	identify(ptr);
	std::cout << std::endl << "ref:" << std::endl;
	identify(ref);

	delete ptr;
	return (0);
}
