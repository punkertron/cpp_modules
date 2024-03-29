#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal(const std::string str);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& a);
	WrongAnimal& operator=(const WrongAnimal &a);

	std::string	getType() const;

	void	makeSound() const;
};

#endif