#include <iostream>
#include "Harl.hpp"

void play_script(Harl HAL_9000)
{
	std::cout << dave_1 << std::endl << std::endl;
	HAL_9000.complain("OPEN");
	std::cout << dave_2 << std::endl << std::endl;
	HAL_9000.complain("DEBUG");
	std::cout << dave_3 << std::endl << std::endl;
	HAL_9000.complain("INFO");
	std::cout << dave_4 << std::endl << std::endl;
	HAL_9000.complain("WARNING");
	std::cout << dave_5 << std::endl << std::endl;
	HAL_9000.complain("ERROR");
}

int main(int ac, char** av)
{
	Harl HAL_9000;

	std::cout << std::endl;
	if (ac < 2)
	{
		HAL_9000.complain("OPEN");
		HAL_9000.complain("DEBUG");
		HAL_9000.complain("INFO");
		HAL_9000.complain("WARNING");
		HAL_9000.complain("ERROR");
	}
	else
	{
		int i = 0;
		while (++i < ac)
		{
			std::string mode;

			int j = -1;
			while (av[i][++j])
				mode += toupper(av[i][j]);
			if (!mode.compare("SCRIPT"))
				play_script(HAL_9000);
			else
				HAL_9000.complain(mode);
		}
	}
}