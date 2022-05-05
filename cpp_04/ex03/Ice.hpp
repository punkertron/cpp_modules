#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	std::string	m_name;
private:
	Ice();
	~Ice();
	Ice(const Ice &a);
	Ice& operator=(const Ice &a);

	virtual AMateria* clone() const;
};

#endif