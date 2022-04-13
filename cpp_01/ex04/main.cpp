#include "my_func.hpp"

int main(int argc, char **argv)
{
	std::fstream	filein;
    std::fstream	fileout;
	std::string		strTemp;
	size_t			len = 0;

	if (argc != 4)
	{
		std::cerr << "Error! Args: filename, s1, s2" << std::endl;
		return (1);
	}
	
	filein.open(argv[1], std::ios::in); //File to read from
	if (!filein.is_open())
	{
		std::cerr << "Cannot open input file" << std::endl;
		return (2);
	}

	fileout.open(std::string(argv[1]).append(".replace").c_str(), std::ios::out); //Out file
    if (!fileout.is_open())
	{
		std::cerr << "Cannot open output file" << std::endl;
		filein.close();
		return (3);
	}

	len = std::string(argv[2]).length();
	while(getline(filein, strTemp))
	{
		if (!filein.eof())
			fileout << replace_func(strTemp, argv[2], argv[3], len) << std::endl;
		else
			fileout << replace_func(strTemp, argv[2], argv[3], len);
	}
	filein.close();
	fileout.close();

    return (0);
}
