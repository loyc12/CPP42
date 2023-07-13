#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		ClapTrap Clapper("CLAPPER");

		std::cout << std::endl << std::endl;

		Clapper.showStats();

		Clapper.attack("TRAPPER");
		Clapper.takeDamage(3);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.beRepaired(1);
		Clapper.takeDamage(16);
		Clapper.beRepaired(1);
		Clapper.takeDamage(42);

		Clapper.showStats();
	}
	std::cout << std::endl << std::endl << "O================================================================O" << std::endl;
}