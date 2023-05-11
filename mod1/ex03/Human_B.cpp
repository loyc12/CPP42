#include "Human_B.hpp"

Human_B::Human_B(std::string name_)
{
	std::cout << "Human_A()  | " << name_ << " was born" << std::endl;
	this->name = name_;
	this->weapon = NULL;
}

Human_B::~Human_B()
{
	std::cout << "~Human_A() | " << this->name << " died a gruesome death" << std::endl;
}

void Human_B::setWeapon(Weapon *weapon_)
{
	std::cout << "Human_A()  | " << this->name << " picked up a " << weapon_->getType() << std::endl;
	this->weapon = weapon_;
}

void Human_B::attack() const
{
	std::cout << "attack()   | " << this->name << " attacked with their " << this->weapon->getType() << std::endl;
}
