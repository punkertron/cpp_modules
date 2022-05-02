#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string const & name);
	FragTrap(const FragTrap &a);
	FragTrap& operator=(const FragTrap &a);
	
	void	highFivesGuys(void);
};

#endif