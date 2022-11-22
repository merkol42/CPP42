#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (42)
	{
		std::cout << "$>";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
			phonebook.add_contact();
		else if (!command.compare("SEARCH"))
			phonebook.search();
		else if (!command.compare("EXIT") || std::cin.eof())
		{
			std::cout << std::endl << "Byee!" << std::endl;
			break ;
		}
		else if (!command.compare("clear"))
			std::cout << "\033[2J" << "c\033[H";
		else if (command.length())
			std::cout << "Unknown command!" << std::endl;
		command = "";
	}
	return (0);
}