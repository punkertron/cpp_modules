#ifndef MUTANT_STACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

//#include <iterator>

template <typename T>

class MutantStack: public std::stack<T>
{
public:
	MutantStack(): std::stack<T>(){}
	MutantStack(const MutantStack<T> &a): std::stack<T>(a){}
	~MutantStack(){}
	MutantStack& operator=(const MutantStack<T> &a)
	{
		this->c = a.c;
		return (*this);
	}

	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename std::stack<T>::container_type::iterator		iterator;

	iterator begin()
	{
		return( this->c.begin());
	}

	const_iterator begin() const
	{
		return(this->c.begin());
	}

	iterator end()
	{
		return(this->c.end());
	}

	const_iterator end() const
	{
		return(this->c.end());
	}
};

#endif /* MutantStack.hpp */