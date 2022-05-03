#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

#ifndef ARR_SIZE
# define ARR_SIZE 100
#endif

class Brain
{
private:
	std::string	ideas[ARR_SIZE];

public:
	Brain();
	~Brain();
	Brain(const Brain &a);
	Brain& operator=(const Brain &a);
};

#endif