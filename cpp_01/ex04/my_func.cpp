#include "my_func.hpp"

std::string	replace_func(std::string strTemp, char *s1, char *s2, size_t len)
{
	size_t	index = 0;
	
	if (len == 0) {return ("");};

	while((index = strTemp.find(s1, index)) != std::string::npos)
	{
		strTemp.erase(index, len);
		strTemp.insert(index, s2);
		index += len;
	};
	return(strTemp);
}
