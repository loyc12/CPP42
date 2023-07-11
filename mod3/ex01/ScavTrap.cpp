#include "ScavTrap.hpp"

// Constructors / Destructor

ScavTrap::ScavTrap(std::string _name)
{
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	this->Name = _name;
	std::cout << "[ default constructor called (" << this->Name << ") ] ";
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other.Name;
	std::cout << "[ copy constructor called (" << this->Name << ") ] ";
}
ScavTrap &ScavTrap::operator= (const ScavTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other.Name;
	std::cout << "[ operator constructor called (" << this->Name << ") ] ";
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "[ destructor called (" << this->Name << ") ] ";
}

//	Others
void ScavTrap::guardGate(void)
{
	std::cout << "> " << this->Name << " enters 'GUARD KEEPER' mode" << std::endl << std::endl;
}