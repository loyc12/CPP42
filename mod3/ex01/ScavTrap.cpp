#include "ScavTrap.hpp"

// Constructors / Destructor

ScavTrap::ScavTrap(string _name)
{
	this->HP = 100;
	this->EP = 50;
	this->AD = 20;
	this->Name = _name;
	std::cout << "[ default constructor called (ScavTrap : " << this->Name << " ) ] ";
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other->Name;
	std::cout << "[ copy constructor called (ScavTrap : " << this->Name << " ) ] ";
}
ScavTrap &ScavTrap::operator= (const ScavTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	this->Name = other->Name;
	std::cout << "[ operator constructor called (ScavTrap : " << this->Name << " ) ] ";
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "[ destructor called (ScavTrap : " << this->Name << " ) ] ";
}

//	Others
