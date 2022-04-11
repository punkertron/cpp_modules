#include <iostream>
#include <string>

int main(void)
{
	std::string		str("HI THIS IS BRAIN");
	std::string*	ptr = &str;
	std::string&	ref = str;

	std::cout
		<< "String address: " << &str << std::endl
		<< "Ponter address: " << ptr  << std::endl
		<< "Ref    address: " << &ref << std::endl;
	
	std::cout << std::endl;
	
	std::cout
		<< "String   value: " << str << std::endl
		<< "Ponter   value: " << *ptr << std::endl
		<< "Ref      value: " << ref << std::endl;


	return (0);
}