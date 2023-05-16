#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *z = new Zombie;

	z->setName(name);

	std::cout << "newZombie() | Returning named zombie" << std::endl;

	return (z);
}
