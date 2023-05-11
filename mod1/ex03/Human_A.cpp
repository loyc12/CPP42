#include "Human_A.hpp"

Human_A::Human_A(std::string name_, Weapon &weapon_) : weapon(weapon_)
{
	std::cout << "Human_A()  | " << name_ << " was born with a " << weapon_.getType() << std::endl;
	this->name = name_;
	this->weapon = weapon_;
}

Human_A::~Human_A()
{
	std::cout << "~Human_A() | " << this->name << " died a gruesome death" << std::endl;
}

void Human_A::attack() const
{
	std::cout << "attack()   | " << this->name << " attacked with their " << this->weapon.getType() << std::endl;
}
