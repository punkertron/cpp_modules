#include "PhoneBook.hpp"
#include <iomanip>
#include <string_view>

static void	manual()
{
	std::cout << "Welcome to the Awesome Phonebook!" << std::endl;
	std::cout << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "ADD - add new contact" << std::endl;
	std::cout << "SEARCH - show all and show specific" << std::endl;
	std::cout << "EXIT - you can guess :-)" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	PhoneBook	myBook;
	std::string	input;

	manual();
	while(true)
	{
		std::cout << "Enter a command: ";
		std::cin >> input;
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			myBook.add();
		else if (input == "SEARCH")
			myBook.search();
		else
			std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	}
	std::cout << std::endl << "Bye-Bye!" << std::endl;
	return (0);
}
