#include <iostream>
#include <cctype>

int main (int argc, char **argv)
{
	int	a, i;

	a = 1;
	while (a < argc)
	{
		i = 0;
		while (argv[a][i])
		{
			std::cout << static_cast<char>(toupper(argv[a][i]));
			i++;
		}
		a++;
	}
	if (a == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
