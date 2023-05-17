#include <iostream>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	//tests HumanA
	std::cout << std::endl << "[ Human A ]" << std::endl << std::endl;
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
	//tests HumanB
	std::cout << std::endl << std::endl << "[ Human B ]" << std::endl << std::endl;
	{
		Weapon sword = Weapon("longsword");

		std::cout << std::endl;

		HumanB billy("Billy");
		billy.setWeapon(sword);
		billy.attack();

		std::cout << std::endl;

		sword.setType("rapier");
		billy.attack();

		std::cout << std::endl;
	}
	std::cout << std::endl;
}
