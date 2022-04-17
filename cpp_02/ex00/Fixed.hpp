#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	val;
	static const int num_fractional = 8;

public:
	Fixed();
	Fixed(const Fixed &a);
	Fixed& operator=(const Fixed &a);

	~Fixed();

	int getRawBits( void ) const;

	void setRawBits( int const raw );
};

#endif