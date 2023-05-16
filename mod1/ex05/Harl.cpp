#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << debug_message << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << info_message << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << warning_message << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << error_message << std::endl << std::endl;
}

void Harl::invalid(void)
{
	std::cout << invalid_message << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	func_ptr funcs[5] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::invalid
	};

	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};


	int i = 0;
	while (i < 4 && level.compare(levels[i]))
		i++;

	(this->*funcs[i])();
}
