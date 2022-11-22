#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Form;

class PresidentialPardonForm : public Form
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);
		
		std::string	getTarget() const;
		
		void execute(const Bureaucrat& executor) const;
};

#endif