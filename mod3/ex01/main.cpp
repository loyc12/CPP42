#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		ClapTrap Clapper("CLAPPER");

		std::cout << std::endl << std::endl;

		Clapper.showStats();

		Clapper.attack("TRAPPER");
		Clapper.takeDamage(5);
		Clapper.beRepaired(1);

		Clapper.showStats();
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		ScavTrap Scaver("SCAVER");

		std::cout << std::endl << std::endl;

		Scaver.showStats();

		Scaver.attack("TRAPPER");
		Scaver.takeDamage(5);
		Scaver.beRepaired(1);
		Scaver.guardGate();

		Scaver.showStats();
	}
	std::cout << std::endl << std::endl << "O================================================================O" << std::endl;
}