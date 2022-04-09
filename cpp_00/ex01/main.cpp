#include "PhoneBook.hpp"
#include <iomanip>
#include <string_view>

int main(void)
{
	PhoneBook	myBook;
	std::string	input;

	while(true)
	{
		std::cin >> input;
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			myBook.add();
		else if (input == "SEARCH")
			std::cout << "SEARCH\n";
		else
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	}
	
	return (0);
}