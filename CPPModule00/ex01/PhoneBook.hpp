#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int	index;
public:
	PhoneBook();
	~PhoneBook();

	void	add_contact();
	void	search();
	void	search(int i);
};

#endif