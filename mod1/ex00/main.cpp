#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	//tests randomChump()
	std::cout << " - Testing randomChump() :" << std::endl;
	randomChump("Randy Random");

	std::cout << std::endl;

	//tests newZombie()
	std::cout << " - Testing newZombie() :" << std::endl;
	Zombie *z = newZombie("Patrick Particular");
	z->announce();
	delete z;

	std::cout << std::endl;
}