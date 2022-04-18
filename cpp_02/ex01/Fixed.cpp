#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int b)
{
	std::cout << "Int constructor called" << std::endl;
	this->val = b << this->num_fractional;

	//std::cout << this->val << std::endl;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->val = (int)f << this->num_fractional;
	std::cout << val << std::endl;
	std::cout << (val >> 8) << std::endl;
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

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->val));
}

int	Fixed::toInt( void ) const
{
	return (this->val >> this->num_fractional);
}
