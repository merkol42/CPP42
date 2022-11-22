#include "Converter.hpp"
#include <limits.h>
#include <string>

static void	ft_msg(std::string msg)
{
	std::cout << msg << std::endl;
}

Converter::Converter() : str("Default")
{
	std::cout << "Convertor Default Constructor Called!" << std::endl;
}

Converter::Converter(std::string str) : str(str)
{
	std::cout << "Convertor String Constructor Called!" << std::endl;
}

Converter::~Converter()
{
	std::cout << "Converter has been destroyed" << std::endl;
}

Converter::Converter(const Converter& ref)
{
	str = ref.getStr();
	std::cout << "Convertor Coppy Constructor Called!" << std::endl;
}

Converter &	Converter::operator=(const Converter& ref)
{
	str = ref.getStr();
	std::cout << "Assignement operator called" << std::endl;
	return (*this);
}

std::string Converter::getStr() const
{
	return (this->str);
}

static int	is_printable_char(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

Converter::operator char()
{
	char c = 0;
	std::cout << "char: ";
	if (str.length() == 1)
	{
		int d = 0;
		try
		{
			d = stoi(str);
			c = static_cast<char>(d);
		}
		catch (const std::invalid_argument& ia){
			c = str[0];
		}
		if (is_printable_char(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		return (c);
	}
	else
	{
		int	d = 0;
		try
		{
			d = stoi(str);
		}
		catch (const std::invalid_argument& ia)
		{
			std::cout << "Impossible: invalid argument" << std::endl;
			return (0);
		}
		catch (const std::out_of_range& oor)
		{
			std::cout << "Impossible: out of range" << std::endl;
			return (0);
		}
		if (d < CHAR_MIN || d > CHAR_MAX)
		{
			std::cout << "Impossible: out of range" << std::endl;
			return (0);
		}
		c = static_cast<char>(d);
		if (is_printable_char(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		return (c);
	}
}

Converter::operator int()
{
	int	d = 0;
	std::cout << "int: ";
	try
	{
		d = stoi(str);
		std::cout << d << std::endl;
	}
	catch (const std::invalid_argument& ia)
	{
		std::cout << "Impossible: invalid argument" << std::endl;
		return (0);
	}
	catch (const std::out_of_range& oor)
	{
		std::cout << "Impossible: out of range" << std::endl;
		return (0);
	}
	return (d);
}

Converter::operator float()
{
	float	f = 0;
	std::cout << "float: ";
	try
	{
		f = stof(str);
		std::cout << f << "f" << std::endl;
	}
	catch (const std::invalid_argument& ia)
	{
		std::cout << "Impossible: invalid argument" << std::endl;
		return (f);
	}
	catch (const std::out_of_range& oor)
	{
		std::cout << "Impossible: out of range" << std::endl;
		return (f);
	}
	return (f);
}

Converter::operator double()
{
	double	d = 0;
	std::cout << "double: ";
	try
	{
		d = stod(str);
		std::cout << d << std::endl;
	}
	catch (const std::invalid_argument& ia)
	{
		std::cout << "Impossible: invalid argument" << std::endl;
		return (d);
	}
	catch (const std::out_of_range& oor)
	{
		std::cout << "Impossible: out of range" << std::endl;
		return (d);
	}
	return (d);
}