#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->val = a.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(a);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function call" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits( int const raw )
{
	this->val = raw;
	return ;
}
