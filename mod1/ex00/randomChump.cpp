#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie z;

	z.setName(name);

	z.announce();
}
