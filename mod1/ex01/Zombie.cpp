#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie()  | A survivor got bit and turned" << std::endl;
	this->name = "UNINITIALIZED";
}

Zombie::~Zombie()
{
	std::cout << "~Zombie() | \'" << this->name << "\' ate 12 gauge of lead to the face" << std::endl;
}

void Zombie::setName(std::string name)
{
	std::cout << "setName() | This zombie was once named \'" << name << "\'" << std::endl;
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