#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:

	class Contact m_contact[7];
	int	m_len;

public:

	PhoneBook()
	{
		m_len = 0;
	}

	void add()
	{
		m_contact[m_len].add();
		m_len++;
	}
};

#endif