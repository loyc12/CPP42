#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	std::cout << std::endl;
	{
		Weapon sword = Weapon("longsword");

		std::cout << std::endl;

		HumanA alice("Alice", sword);
		alice.attack();

		std::cout << std::endl;

		sword.setType("rapier");
		alice.attack();

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	{
		Weapon sword = Weapon("longsword");

		std::cout << std::endl;

		HumanB billy("Billy");
		billy.setWeapon(&sword);
		billy.attack();

		std::cout << std::endl;

		sword.setType("rapier");
		billy.attack();

		std::cout << std::endl;
	}
	std::cout << std::endl;
}
