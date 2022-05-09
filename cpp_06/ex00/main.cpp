#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>

enum e_begin
{
	CHAR_P, INT_P, FLOAT_P, DOUBLE_P
};

static void	printBegin(e_begin a)
{
	switch (a)
	{
	case CHAR_P:
		std::cout << "char: ";
		break;
	case INT_P:
		std::cout << "int: ";
		break;
	case FLOAT_P:
		std::cout << "float: ";
		break;
	case DOUBLE_P:
		std::cout << "double: ";
		break;
	}
}

static bool	charOverflow(const double &a)
{
	return (a > std::numeric_limits<char>::max() || a < std::numeric_limits<char>::min());
}

static bool	intOverflow(const double &a)
{
	return (a > std::numeric_limits<int>::max() || a < std::numeric_limits<int>::min());
}

static bool isNumber(const double &a)
{
	return (!std::isnan(a) && std::isfinite(a));
}

static bool	checkNanInf(const std::string &a)
{
	return (a.find("nan") != std::string::npos || a.find("inf") != std::string::npos);
}

static	void charConvert(const char &c)
{
	printBegin(CHAR_P);
	if (charOverflow(static_cast<double>(c)))
		std::cout << "impossible\n";
	if (!isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << c << "'\n";
	printBegin(INT_P);
	std::cout << static_cast<int>(c) << std::endl;
	printBegin(FLOAT_P);
	std::cout << static_cast<float>(c) << 'f' << std::endl;
	printBegin(DOUBLE_P);
	std::cout << static_cast<double>(c) << std::endl;
}


static void	floatConvert(const float &f)
{
	printBegin(CHAR_P);
	if (!isNumber(f) || charOverflow(static_cast<double>(f)))
		std::cout << "impossible\n";
	else if (!isprint(f))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	
	printBegin(INT_P);
	if (!isNumber(static_cast<double>(f)) || intOverflow(static_cast<double>(f)))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(f) << std::endl;

	printBegin(FLOAT_P);
	std::cout << f << 'f' << std::endl;
	printBegin(DOUBLE_P);
	std::cout << static_cast<double>(f) << std::endl;
}


static void	doubleConvert(const double &d)
{
	printBegin(CHAR_P);
	if (charOverflow(d))
		std::cout << "impossible\n";
	else if (!isprint(d))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	

	printBegin(INT_P);
	if (intOverflow(d) || !isNumber(d))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << std::endl;

	printBegin(FLOAT_P);
	std::cout << static_cast<float>(d) << 'f' << std::endl;
	printBegin(DOUBLE_P);
	std::cout << d << std::endl;
}


static void intConvert(const long &i)
{
	printBegin(CHAR_P);
	if (charOverflow(static_cast<double>(i)))
		std::cout << "impossible\n";
	else if (!isprint(i))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	
	printBegin(INT_P);
	if (intOverflow(static_cast<double>(i)))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(i) << std::endl;

	printBegin(FLOAT_P);
	std::cout << static_cast<float>(i) << 'f' << std::endl;
	printBegin(DOUBLE_P);
	std::cout << static_cast<double>(i) << std::endl;;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong argumets" << std::endl;
		return (1);
	}
	std::string	input = argv[1];
	std::cout << std::setprecision(1) << std::fixed;


	if (input[0] == '\'' && !checkNanInf(input))
		charConvert(static_cast<char> (input[1]));
	else if (input.find('f') != std::string::npos || checkNanInf(input))
		floatConvert(static_cast<float>(std::strtof(input.c_str(), NULL)));
	else if (input.find('.') != std::string::npos)
		doubleConvert(static_cast<double>(std::strtod(input.c_str(), NULL)));
	else
		intConvert(static_cast<long>(std::strtol(input.c_str(), NULL, 10)));
	return (0);
}
