#include <iostream>
#include "Harl.hpp"

int main(int ac, char** av)
{
	Harl HAL_9000;

	std::cout << std::endl;
	if (ac != 2)
		std::cout << "Please specify a single logging level" << std::endl << std::endl;
	else
	{
		int i = -1;
		std::string mode;

		while (av[1][++i])
			mode += toupper(av[1][i]);

		HAL_9000.complain(mode);
	}
}