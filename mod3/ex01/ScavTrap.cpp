#include "ScavTrap.hpp"

// Constructors / Destructor

ScavTrap::ScavTrap()
{
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	this->Name = "UNINITIALIZED";
	std::cout << "[ default constructor called (SCAVTRAP : " << this->Name << ") ] ";
}
ScavTrap::ScavTrap(std::string _name)
{
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	this->Name = _name;
	std::cout << "[ default constructor called (SCAVTRAP : " << this->Name << ") ] ";
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other.Name;
	std::cout << "[ copy constructor called (SCAVTRAP : " << this->Name << ") ] ";
}
ScavTrap &ScavTrap::operator= (const ScavTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other.Name;
	std::cout << "[ operator constructor called (SCAVTRAP : " << this->Name << ") ] ";
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "[ destructor called (SCAVTRAP : " << this->Name << ") ] ";
}

//	Others
void ScavTrap::attack(const std::string& target)
{
	if (canAct())
	{
		this->EP -= 1;
		std::cout << "> a wild " << target << " appeared!" << std::endl;
		std::cout << this->Name << " uses 'SCAV_ATTACK' on " << target << std::endl;
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
void ScavTrap::guardGate(void)
{
	std::cout << this->Name << " enters 'GUARD_KEEPER' mode" << std::endl << std::endl;
}