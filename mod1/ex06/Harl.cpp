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

int Harl::find_level_id(std::string level)
{
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int i = 0;
	while (i < 4 && level.compare(levels[i]))
		i++;

	return (i);
}

void Harl::complain(std::string level)
{

	std::cout << "[ LOGGING LEVEL : " << level << " ]" << std::endl << std::endl;
	switch (this->find_level_id(level))
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break; // prevents printing default case exists
		default:
			this->invalid();
	}
}
