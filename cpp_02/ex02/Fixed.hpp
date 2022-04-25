#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
private:
	int	val;
	static const int num_fractional = 8;

public:
	Fixed();
	Fixed(const int b);
	Fixed(const float f);

	Fixed(const Fixed &a);
	Fixed& operator=(const Fixed &a);

	~Fixed();

	int getRawBits( void ) const;

	void setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;


	/*ex01*/
	
	/*comparison*/

	bool	operator>(const Fixed b) const;
	bool	operator<(const Fixed b) const;
	bool	operator>=(const Fixed b) const;
	bool	operator<=(const Fixed b) const;
	bool	operator==(const Fixed b) const;
	bool	operator!=(const Fixed b) const;

	/*arithmetic */
	Fixed	operator+(const Fixed b) const;
	Fixed	operator-(const Fixed b) const;
	Fixed	operator/(const Fixed b) const;
	Fixed	operator*(const Fixed b) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &Fixed);

#endif