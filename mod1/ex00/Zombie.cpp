#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A survivor got bit and turned" << std::endl;
	this->name = "UNINITIALIZED";
}

Zombie::~Zombie()
{
	std::cout << this->name << " caught 12 gauge of lead with their face" << std::endl;
}

void Zombie::setName(std::string name)
{
	std::cout << "This zombie was named " << name << std::endl;
	this->name = name;
}

std::string Zombie::getName() const
{
	return (this->name);
}

void Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}