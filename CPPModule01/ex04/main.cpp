#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage [filename][str1][str2]" << std::endl;
		return (0);
	}
	std::string temp = av[1];
	std::fstream file(temp, std::ios::in);
	std::fstream newFile(temp.append(".replace"), std::ios::out);
	if (!newFile || !file)
	{
		std::cout << "File not created!" << std::endl;
		return (1);
	}
	std::stringstream stream;
	stream << file.rdbuf();
	std::string tempData = stream.str();
	std::size_t found = 0;
	while ((found = tempData.find(av[2], found)) != std::string::npos) {
		tempData.erase(found, strlen(av[2]));
		tempData.insert(found, av[3]);
		found += strlen(av[3]);
	}
	newFile << tempData;
	file.close();
	newFile.close();
	return (0);
}