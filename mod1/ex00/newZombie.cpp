#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *z = new Zombie;

	z->setName(name);

	return (z);
}
