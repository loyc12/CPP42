#include<iostream>

#include "Weapon.hpp"
#include "Human_A.hpp"
#include "Human_B.hpp"

int main(void)
{
	std::cout << std::endl;
	{
		Weapon sword = Weapon("longsword");

		std::cout << std::endl;

		Human_A alice = Human_A("Alice", sword);
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

		Human_B billy = Human_B("Billy");
		billy.setWeapon(sword);
		billy.attack();

		std::cout << std::endl;

		sword.setType("rapier");
		billy.attack();

		std::cout << std::endl;

	}
	std::cout << std::endl;
}
