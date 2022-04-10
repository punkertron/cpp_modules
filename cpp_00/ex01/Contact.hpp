#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:

	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone_number;
	std::string m_darkest_secret;

public:

	Contact();
	~Contact();

	void	add();

	void	print_all(const int a) const;

	void	print_exact(const int index) const;
};

#endif