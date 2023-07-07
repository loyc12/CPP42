#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Clapper;

	std::cout << std::endl << std::endl;

	Clapper.showStats();

	Clapper.attack("TRAPPER");
	Clapper.takeDamage(5);
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
	Clapper.takeDamage(20);
	Clapper.beRepaired(1);
	Clapper.takeDamage(20);

	Clapper.showStats();

	std::cout << std::endl;
}