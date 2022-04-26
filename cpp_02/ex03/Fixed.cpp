#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): val(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int b)
{
	//std::cout << "Int constructor called" << std::endl;
	this->val = b << this->num_fractional;
}

Fixed::Fixed(const float f)
{
	//std::cout << "Float constructor called" << std::endl;
	this->val = roundf(f * (1 << num_fractional));
}

Fixed& Fixed::operator=(const Fixed &a)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->val = a.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &a)
{
	//std::cout << "Copy constructor called" << std::endl;
	operator=(a);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function call" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits( int const raw )
{
	this->val = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	return (this->val / float(1 << num_fractional));
}

int	Fixed::toInt( void ) const
{
	return (this->val >> this->num_fractional);
}

std::ostream& operator<<(std::ostream &out, const Fixed &Fixed)
{
	out << Fixed.toFloat();

	return (out);
}



/*ex01*/

/*comparison*/

bool	Fixed::operator>(const Fixed &b) const
{
	return (this->getRawBits() > b.getRawBits());
}

bool	Fixed::operator<(const Fixed &b) const
{
	return (this->getRawBits() < b.getRawBits());
}

bool	Fixed::operator>=(const Fixed &b) const
{
	return (this->getRawBits() >= b.getRawBits());
}

bool	Fixed::operator<=(const Fixed &b) const
{
	return (this->getRawBits() <= b.getRawBits());
}

bool	Fixed::operator!=(const Fixed &b) const
{
	return (this->getRawBits() != b.getRawBits());
}

bool	Fixed::operator==(const Fixed &b) const
{
	return (this->getRawBits() == b.getRawBits());
}



/*arithmetic */

Fixed	Fixed::operator+(const Fixed &b) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() + b.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &b) const
{
	Fixed res;

	res.setRawBits(this->getRawBits() - b.getRawBits());
	return (res);
}

Fixed	Fixed::operator/(const Fixed &b) const
{
	return (Fixed(this->toFloat() / b.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &b) const
{
	return (Fixed(this->toFloat() * b.toFloat()));
}


/*increment/decrement*/

Fixed&	Fixed::operator++()
{
	++(this->val);
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--(this->val);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp.setRawBits(this->getRawBits());
	++(*this);

	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp.setRawBits(this->getRawBits());
	--(*this);

	return (temp);
}


/*max and min*/

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
