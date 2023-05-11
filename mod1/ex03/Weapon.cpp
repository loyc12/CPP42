#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	std::cout << "Weapon()   | Forged a " << type << std::endl;
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "~Weapon()  | A " << this->type << " crumbled to dust" << std::endl;
}

void Weapon::setType(std::string newType)
{
	std::cout << "setType()  | Weapon changed from " << this->type << " to " << newType << std::endl;
	this->type = newType;
}

std::string Weapon::getType() const
{
	return (this->type);
}
