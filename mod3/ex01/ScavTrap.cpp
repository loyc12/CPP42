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
void ScavTrap::guardGate(void)
{
	std::cout << this->Name << " enters 'GUARD_KEEPER' mode" << std::endl << std::endl;
}