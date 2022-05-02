#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

#ifndef M_NUMBER_HIT
# define M_NUMBER_HIT 10
#endif

#ifndef M_NUMBER_DAMAGE
# define M_NUMBER_DAMAGE 0
#endif

class ClapTrap
{
protected:
	std::string	m_name;
 	int	m_attack; //damage to this
	int	m_energy; //energe
	int	m_hit; //health

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &a);
	ClapTrap& operator=(const ClapTrap &a);

	ClapTrap(std::string const & name);

	ClapTrap(std::string const & name, int hit, int energy, int attack);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string	getName() const;
	int			getAttack() const;
	int			getEnergy() const;
	int			getHit() const;

	void		setEnergy(int new_energy);
	void		setHit(int new_hit);
	void		setAttack(int new_attack);
	void		setName(std::string new_name);
};

#endif