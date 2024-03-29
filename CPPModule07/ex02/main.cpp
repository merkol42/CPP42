#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		std::cout << "-------------------------" << std::endl;
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	std::cout << "-------------------------" << std::endl;
	//mirror[5] = numbers[1];
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		std::cout << "Invalid Index!!" << std::endl;
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		std::cout << "Invalid Index!!" << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	std::cout << "---------------------" << std::endl;
	Array<int> index(5);
	Array<char>	sa(5);
	sa[0] = 'A';
	std::cout << sa[0] << std::endl;
	std::cout << index[2] << std::endl;
	
	std::cout << index << std::endl;
	std::cout << sa << std::endl;

	// std::system("leaks array");
	return 0;
}