#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	std::string	name;
	std::string	lastname;
	std::string	nickname;
	std::string	telnumber;
	std::string	secret;
public:
	Contact();
	~Contact();

	void	set_contact(Contact *person);
	void	print_contact(Contact person, int index);
	void	print_contact(Contact *contacts, int index);
};

#endif