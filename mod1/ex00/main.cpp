#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	//tests randomChump()
	std::cout << "[ randomChump() ]" << std::endl << std::endl;
	randomChump("Randy Random");

	std::cout << std::endl << std::endl;

	//tests newZombie()
	std::cout << "[ newZombie() ]" << std::endl << std::endl;
	Zombie *z = newZombie("Patrick Particular");
	std::cout << std::endl;
	z->announce();
	delete z;
}