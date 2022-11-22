#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string bellek adresi            :" << &str << std::endl;
	std::cout << "stringPTR tuttuğu bellek adresi :" << stringPTR << std::endl;
	std::cout << "stringREF tuttuğu bellek adresi :" << &stringREF << std::endl;

	std::cout << "----------------------------" << std::endl;

	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}