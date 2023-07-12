#include "FragTrap.hpp"

// Constructors / Destructor

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
void FragTrap::hiFiveGuys(void)
{
	std::cout << "> " << this->Name << " uses 'HI_FIVE' on GUYS" << std::endl << std::endl;
}