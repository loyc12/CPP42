#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon &weapon_) : weapon(weapon_)
{
	std::cout << "HumanA()   | " << name_ << " was born with a " << weapon_.getType() << std::endl;
	this->name = name_;
	this->weapon = weapon_;
}

HumanA::~HumanA()
{
	std::cout << "~HumanA()  | " << this->name << " died a gruesome death" << std::endl;
}

void HumanA::attack() const
{
	std::cout << "attack()   | " << this->name << " attacked with their " << this->weapon.getType() << std::endl;
}
