#include "Human_A.hpp"

Human_A::Human_A()
{
	this->name = "NOBODY";
}

Human_A::Human_A(std::string name, Weapon weapon)
{
	std::cout << "Human_A()  | " << name << " was born with a " << weapon.getType() << std::endl;
	this->weapon = weapon;
	this->name = name;
}

Human_A::~Human_A()
{
	std::cout << "~Human_A() | " << this->name << " died a gruesome death" << std::endl;
}

void Human_A::attack()
{
	std::cout << "attack()   | " << this->name << " attacked with a " << this->weapon.getType() << std::endl;
}
