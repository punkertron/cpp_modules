#include "Contact.hpp"

static void	trim_str(std::string &str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
}

void Contact::add()
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
	std::cout << std::endl << "SUCCESSFULLY ADDED!" << std::endl << std::endl;
	trim_str(m_first_name);
	trim_str(m_last_name);
	trim_str(m_nickname);
	trim_str(m_phone_number);
	trim_str(m_darkest_secret);
}
