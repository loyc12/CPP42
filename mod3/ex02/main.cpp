#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		ClapTrap Clapper("CLAPPER");

		std::cout << std::endl << std::endl;

		Clapper.showStats();

		Clapper.attack("TRAPPER");
		Clapper.takeDamage(5);
		Clapper.beRepaired(1);

		Clapper.showStats();
	}
	std::cout << std::endl;
	{
		std::cout << std::endl << std::endl;

		FragTrap Fragger("FRAGGER");

		std::cout << std::endl << std::endl;

		Fragger.showStats();

		Fragger.attack("TRAPPER");
		Fragger.takeDamage(5);
		Fragger.beRepaired(1);
		Fragger.hiFiveGuys();

		Fragger.showStats();
	}
	std::cout << std::endl;
}