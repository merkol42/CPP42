#include "Harl.hpp"

Harl::Harl()
{
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
	this->functions[0] = &Harl::debug;
	this->functions[1] = &Harl::info;
	this->functions[2] = &Harl::warning;
	this->functions[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "debug function" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "info function" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "warning function" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "error function" << std::endl;
}

void	Harl::complain(std::string level)
{
	for (size_t i = 0; i < 4; i++)
		if (!level.compare(this->levels[i]))
			(this->*functions[i])();
}