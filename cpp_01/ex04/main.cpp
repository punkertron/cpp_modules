#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char **argv)
{
	std::fstream filein;
    std::fstream fileout;
	std::string strTemp;

	if (argc != 4)
	{
		std::cerr << "Error! Args: filename, s1, s2" << std::endl;
		return (1);
	}
	
	filein.open(argv[1], std::ios::in); //File to read from
	fileout.open(std::string(argv[1]).append(".replace").c_str(), std::ios::out); //Temporary file
    
	if(filein.is_open() && fileout.is_open())
    {
        while(getline(filein, strTemp))
		{
			if(strTemp == std::string(argv[2])){
				strTemp = std::string(argv[3]);
			}
			fileout << strTemp << std::endl;
		}
		filein.close();
		fileout.close();
    }
	else
	{
		std::cerr << "Error opening files!" << std::endl;
        return (2);
	}
    return (0);
}
