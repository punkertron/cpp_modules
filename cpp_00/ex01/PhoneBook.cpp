#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook(): m_len(0), m_oldest(0) {}

PhoneBook::~PhoneBook() {}

static void	print_header_all()
{
	std::cout << std::endl << std::setw(13) << "" << "My Awesome PhoneBook" << std::endl;
	std::cout << std::setfill('-') << std::setw(45) << "" << std::endl;
	std::cout << "|   index  |first_name|last_name | nickname |" << std::endl
	<< std::setw(45) << "" << std::endl;
}

static void	print_header_exact()
{
	std::cout << std::endl << std::setw(24) << "" << "My Awesome PhoneBook" << std::endl;
	std::cout << std::setfill('-') << std::setw(67) << "" << std::endl;
	std::cout << "|   index  |first_name|last_name | nickname |   phone  |  secret  |" << std::endl
	<< std::setw(67) << "" << std::endl;
}

void	PhoneBook::add()
{	
	if (m_len != MAX_CONTACTS)
	{
		m_len++;
		m_oldest = m_len;
	}
	else
	{
		m_oldest = m_oldest % m_len + 1;
	}
	m_contact[m_oldest - 1].add();
}

void	PhoneBook::search() const
{
	int	a = 1;
	int	index;

	print_header_all();
	while (a <= m_len)
	{
		m_contact[a - 1].print_all(a);
		a++;
	}
	std::cout << std::endl;
	if (m_len > 0)
	{
		while (true)
		{
			std::cout << "SELECT the desired index from the table above to see a contact: ";
			std::cin >> index;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (index > 0 && index <= m_len)
			{
				print_header_exact();
				m_contact[index - 1].print_exact(index);
				std::cout << std::endl;
				break ;
			}
		}
	}

}
