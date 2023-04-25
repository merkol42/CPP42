#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
	
	std::stringstream ss("hello, world");
	std::string word;
	std::getline(ss, word, ',');
	std::streampos pos = ss.tellg();

	std::cout << pos << std::endl;
	return 0;
}
