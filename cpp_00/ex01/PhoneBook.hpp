#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS	8

class PhoneBook
{
private:

	class Contact m_contact[MAX_CONTACTS];
	int	m_len;
	int	m_oldest;

public:

	PhoneBook();
	~PhoneBook();

	void	add();

	void	search() const;
};

#endif