#include "FragTrap.hpp"

// Constructors / Destructor

FragTrap::FragTrap()
{
	this->HP = 100;
	this->EP = 100;
	this->AD = 30;
	this->Name = "UNINITIALIZED";
	std::cout << "[ default constructor called (FRAGTRAP : " << this->Name << ") ] ";
}
FragTrap::FragTrap(std::string _name)
{
	this->HP = 100;
	this->EP = 100;
	this->AD = 30;
	this->Name = _name;
	std::cout << "[ default constructor called (FRAGTRAP : " << this->Name << ") ] ";
}
FragTrap::FragTrap(const FragTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other.Name;
	std::cout << "[ copy constructor called (FRAGTRAP : " << this->Name << ") ] ";
}
FragTrap &FragTrap::operator= (const FragTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other.Name;
	std::cout << "[ operator constructor called (FRAGTRAP : " << this->Name << ") ] ";
	return *this;
}
FragTrap::~FragTrap()
{
	std::cout << "[ destructor called (FRAGTRAP : " << this->Name << ") ] ";
}

//	Others
void FragTrap::attack(const std::string& target)
{
	if (canAct())
	{
		this->EP -= 1;
		std::cout << "> a wild " << target << " appeared!" << std::endl;
		std::cout << this->Name << " uses 'FRAG_ATTACK' on " << target << std::endl;
		if (this->AD > 0)
			std::cout << "> it was super effective (-" << this->AD << " HP)" << std::endl;
		else if (this->AD == 0)
			std::cout << "> it wasn't very effective (-0 HP)" << std::endl;
		else
			std::cout << "> you're just healing it now... (+" << -this->AD << " HP)" << std::endl;
//  	deal actual damage here
//		std::cout << target << " now has N/A HP" << std::endl << std::endl;
		std::cout << "| EP : " << this->EP << " (-1)" << std::endl << std::endl;
	}
}
void FragTrap::hiFiveGuys(void)
{
	std::cout << this->Name << " uses 'HI_FIVE' on GUYS" << std::endl << std::endl;
}