#include <iostream>
#include <string>

typedef unsigned long uintptr_t;

struct Data
{
	int number;
	std::string str;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data Foo = {14, "Cool"};
	Data *data_ptr;
	uintptr_t temp;

	std::cout << "Number is: " << Foo.number << std::endl
		<< "String is : " << Foo.str << std::endl;

	temp = serialize(&Foo);
	data_ptr = deserialize(temp);

	std::cout << std::endl;

	std::cout << "Number is: " << data_ptr->number << std::endl
		<< "String is : " << data_ptr->str << std::endl;

	return (0);
}
