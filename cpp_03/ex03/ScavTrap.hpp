#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string const & name);
	ScavTrap(const ScavTrap &a);
	ScavTrap& operator=(const ScavTrap &a);

	void attack(const std::string& target);
	
	void	guradGate(void);
};

#endif