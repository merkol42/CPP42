#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);
		
		std::string	getTarget() const;
		
		void	execute(const Bureaucrat& executor) const;
};

#endif