#include "HumanB.hpp"

HumanB::HumanB(std::string name_)
{
	std::cout << "HumanB()   | " << name_ << " was born" << std::endl;
	this->name = name_;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << "HumanB()   | " << this->name << " died a gruesome death" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon_)
{
	std::cout << "setWeapon()| " << this->name << " picked up a " << weapon_.getType() << std::endl;
	this->weapon = &weapon_;
}

void HumanB::attack() const
{
	std::cout << "attack()   | " << this->name << " attacked with their " << this->weapon->getType() << std::endl;
}
