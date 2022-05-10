#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span(const unsigned int &i): m_max(i) {}

Span::Span(const Span &a): mul_set(a.mul_set), m_max(a.m_max) {};

Span& Span::operator=(const Span &a)
{
	this->m_max = a.m_max;
	this->mul_set = a.mul_set;

	return (*this);
}

Span::~Span() {};

void Span::addNumber(int i)
{
	if (this->size() < this->m_max)
		mul_set.insert(i);
	else
		throw SetOverflow();
}

void	Span::addNumber(int amount, int value)
{
	for (int i = 0; i < amount; i++)
	{
		addNumber(value);
	}
}

unsigned int Span::size() const
{
	return (this->mul_set.size());
}

int	Span::shortestSpan() const
{
	if (this->size() == 0)
	{
		throw NoElements();
	}
	if (this->size() == 1)
	{
		throw OnlyOneElem();
	}

	int res = std::numeric_limits<int>::max();
	int	temp;
	std::set<int>::const_iterator it = this->mul_set.begin();
	std::set<int>::const_iterator prev = this->mul_set.begin();
	it++;

	while (it != this->mul_set.end())
	{
		temp = std::abs(*it - *prev);
		if (temp < res)
			res = temp;
		++it;
		++prev;
	}
	return (res);
}

int Span::longestSpan() const
{
	if (this->size() == 0)
	{
		throw NoElements();
	}
	if (this->size() == 1)
	{
		throw OnlyOneElem();
	}
	return (std::abs(*--mul_set.end() - *mul_set.begin()));
}


const char* Span::SetOverflow::what() const throw()
{
	return ("The massive is full!");
}

const char* Span::OnlyOneElem::what() const throw()
{
	return ("Only one Element. Add more!");
}

const char* Span::NoElements::what() const throw()
{
	return ("No Elements!");
}
