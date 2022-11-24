#include "iter.hpp"

int main(void)
{
	int			arr_int[4] = {0, 1, 2, 3};
	char		arr_char[8] = "metehan";
	float		arr_float[4] = {1.9f, 4.2f, 4.5f, 5.2f};
	std::string	arr_string[4] = {"zaa", "xd", "hello", "world!"};

	iter(arr_int, 4, print_value);
	iter(arr_char, 7, print_value);
	iter(arr_float, 4, print_value);
	iter(arr_string, 4, print_value);
	return (0);
}