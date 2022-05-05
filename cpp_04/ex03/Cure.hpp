#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	std::string	m_name;
private:
	Cure();
	~Cure();
	Cure(const Cure &a);
	Cure& operator=(const Cure &a);

	virtual AMateria* clone() const;
};

#endif