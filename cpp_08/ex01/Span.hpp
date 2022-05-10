#ifndef SPAN_HPP
# define SPAN_HPP

#include <set>
#include <exception>

class Span
{
private:
	std::multiset<int> mul_set;
	unsigned int	m_max;

	class SetOverflow: public std::exception
	{
		virtual const char* what() const throw();
	};
	class NoElements: public std::exception
	{
		virtual const char* what() const throw();
	};
	class OnlyOneElem: public std::exception
	{
		virtual const char* what() const throw();
	};

	Span();

public:
	Span(const unsigned int &i);
	Span(const Span &a);
	~Span();
	Span& operator=(const Span &a);

	void addNumber(int i);
	void addNumber(int amount, int value);
	int	shortestSpan() const;
	int	longestSpan() const;
	unsigned int	size() const;
};

#endif /* Span.hpp */