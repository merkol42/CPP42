#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

class Converter
{
	private:
		std::string	str;
	public:
		Converter();
		Converter(std::string str);
		Converter(const Converter& ref);
		~Converter();

		Converter &	operator=(const Converter& ref);

		std::string	getStr() const;

		operator char();
		operator int();
		operator float();
		operator double();

};
#endif