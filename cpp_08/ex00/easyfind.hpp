#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFound: public std::exception
{
	virtual const char* what() const throw()
	{
		return ("An Element Not Found!");
	}
};

template <typename T>
typename T::iterator	easyfind(T& a, int i)
{
	typename T::iterator it = find(a.begin(), a.end(), i);
	if (it != a.end())
		return (it);
	throw NotFound();
}

#endif /* Easyfind.hpp */