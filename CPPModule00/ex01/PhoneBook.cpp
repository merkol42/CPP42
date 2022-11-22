#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "1:ADD" << std::endl << "2:SEARCH" << std::endl << "3:EXIT" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	this->index = -1;
	// std::cout << "PhoneBokk construct\n";
}

PhoneBook::~PhoneBook()
{
	// std::cout << "PhoneBokk deconstruct\n";
}

void	PhoneBook::add_contact(void)
{
	this->index++;
	this->contacts->set_contact(&this->contacts[index % 8]);
}

void	PhoneBook::search(void)
{
	int			x;
	std::string	input;

	for (int i = 0; i < 8; i++)
		this->contacts->print_contact(this->contacts[i], i);
	std::cout << "ID> ";
	std::getline(std::cin, input);
	if (input.empty() || std::cin.eof())
		return ;
	x = atoi(input.c_str());
	if (x > 0 && x <= 8)
		search(x - 1);
	else
		std::cout << "Girilen ID aralık dışında" << std::endl;
}

void	PhoneBook::search(int i)
{
	this->contacts->print_contact(this->contacts, i);
}