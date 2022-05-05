#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *brain_ptr;

public:
	Cat();
	~Cat();
	Cat(const Cat &a);
	Cat& operator=(const Cat &a);

	virtual void	makeSound() const;
};

#endif