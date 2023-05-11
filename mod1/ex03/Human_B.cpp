#include "Human_B.hpp"

Human_B::Human_B()
{
	this->name = "NOBODY";
}

Human_B::Human_B(std::string name)
{
	std::cout << "Human_A()  | " << name << " was born" << std::endl;
	this->name = name;
}

Human_B::~Human_B()
{
	std::cout << "~Human_A() | " << this->name << " died a gruesome death" << std::endl;
}

void Human_B::setWeapon(Weapon weapon)
{
	std::cout << "Human_A()  | " << this->name << " picked up a " << weapon.getType() << std::endl;
	this->weapon = weapon;
}

void Human_B::attack()
{
	std::cout << "attack()   | " << this->name << " attacked with a " << this->weapon.getType() << std::endl;
}
