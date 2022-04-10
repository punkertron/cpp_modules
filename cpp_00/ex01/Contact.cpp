#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

static void	trim_str(std::string &str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
}

void	Contact::print_all(const int a) const
{
	std::cout
	<< std::right << "|" << std::setfill(' ')
	<< std::setw(10) << a << "|"
	<< std::setw(10) << m_first_name << "|"
	<< std::setw(10) << m_last_name << "|"
	<< std::setw(10) << m_nickname << "|"
	<< std::endl;
}

void	Contact::print_exact(const int index) const
{
	std::cout
	<< std::right << "|" << std::setfill(' ')
	<< std::setw(10) << index << "|"
	<< std::setw(10) << m_first_name << "|"
	<< std::setw(10) << m_last_name << "|"
	<< std::setw(10) << m_nickname << "|"
	<< std::setw(10) << m_phone_number << "|"
	<< std::setw(10) << m_darkest_secret << "|"
	<< std::endl;
}

void	Contact::add()
{
	std::cout << "First name: ";
	std::cin >> m_first_name;
	std::cout << "Last name: ";
	std::cin >> m_last_name;
	std::cout << "Nickname: ";
	std::cin >> m_nickname;
	std::cout << "Phone number: ";
	std::cin >> m_phone_number;
	std::cout << "Darkest secret: ";
	std::cin >> m_darkest_secret;
	std::cout << std::endl << "CONTACT SUCCESSFULLY ADDED!" << std::endl << std::endl;
	trim_str(m_first_name);
	trim_str(m_last_name);
	trim_str(m_nickname);
	trim_str(m_phone_number);
	trim_str(m_darkest_secret);
}
