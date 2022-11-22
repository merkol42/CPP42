#include "Contact.hpp"

Contact::Contact()
{
	name = "NoName";
	lastname = "NoLastName";
	nickname = "NoNickName";
	telnumber = "NoTelNumber";
	secret = "NoSecret";
}

Contact::~Contact()
{
	//std::cout << "Contact deconstruct\n";
}

void	Contact::set_contact(Contact *person)
{
	while (42)
	{
		std::cout << "Name :";
		if (!std::getline(std::cin, person->name)) break ;
		std::cout << "Last Name :";
		if (!std::getline(std::cin, person->lastname)) break ;
		std::cout << "Nick Name :";
		if (!std::getline(std::cin, person->nickname)) break ;
		std::cout << "Tel Number :";
		if (!std::getline(std::cin, person->telnumber)) break ;
		std::cout << "Darkest Secret :";
		if (!std::getline(std::cin, person->secret)) break ;
		if (person->name.size() == 0 || person->lastname.size() == 0 || person->nickname.length() == 0 \
			|| (person->telnumber.length() == 0 || !atoi(person->telnumber.c_str())) || person->secret.length() == 0)
			std::cout << "Kişi bilgileri hatalı veya boş tekrar deneyiniz" << std::endl << "-----------------------------" << std::endl;
		else
		{
			std::cout << "Kayıt başarılı" << std::endl;
			break ;
		}
	}
}

void	Contact::print_contact(Contact person, int index)
{
	std::cout << index + 1 << " |";
	std::cout << std::setw(10) << (person.name.size() > 9 ? person.name.erase(9).append(".") : person.name) << "|";
	std::cout << std::setw(10) << (person.lastname.size() > 9 ? person.lastname.erase(9).append(".") : person.lastname) << "|";
	std::cout << std::setw(10) << (person.nickname.size() > 9 ? person.nickname.erase(9).append(".") : person.nickname) << "|";
	std::cout << std::setw(10) << (person.telnumber.size() > 9 ? person.telnumber.erase(9).append(".") : person.telnumber) << "|";
	std::cout << std::endl;
}

void	Contact::print_contact(Contact *contacts, int index)
{
	std::cout << "Name		: " << contacts[index].name << std::endl;
	std::cout << "LastName	: " << contacts[index].lastname << std::endl;
	std::cout << "NickName	: " << contacts[index].nickname << std::endl;
	std::cout << "TelNumber	: " << contacts[index].telnumber << std::endl;
	std::cout << "DarkestSecret	: " << contacts[index].secret << std::endl;
}