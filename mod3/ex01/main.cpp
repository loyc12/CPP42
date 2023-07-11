#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Scaver;

	std::cout << std::endl << std::endl;

	Scaver.showStats();

	Scaver.attack("TRAPPER");
	Scaver.takeDamage(5);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.beRepaired(1);
	Scaver.takeDamage(20);
	Scaver.beRepaired(1);
	Scaver.takeDamage(20);

	Scaver.showStats();

	std::cout << std::endl;
}