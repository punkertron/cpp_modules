#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>

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



static	void charConvert(const char &c)
{
	printBegin(CHAR_P);
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
	if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
		std::cout << "impossible\n";
	else if (!isprint(f))
		std::cout << "Non displayable\n";
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

	if (input[0] == '\'')
		charConvert(static_cast<char> (input[1]));
	if (input.find('f') != std::string::npos)
		floatConvert(static_cast<float>((std::strtof(input.c_str(), NULL))));

	return (0);
}
