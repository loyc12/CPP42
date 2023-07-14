#include "ClapTrap.hpp"

// Constructors / Destructor

ClapTrap::ClapTrap()
{
	this->HP = 10;
	this->EP = 10;
	this->AD = 0;
	this->Name = "UNINITIALIZED";
	std::cout << "[ default constructor called (CLAPTRAP : " << this->Name << ") ] ";
}
ClapTrap::ClapTrap(std::string _name)
{
	this->HP = 10;
	this->EP = 10;
	this->AD = 0;
	this->Name = _name;
	std::cout << "[ default constructor called (CLAPTRAP : " << this->Name << ") ] ";
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	std::cout << "[ copy constructor called (CLAPTRAP : " << this->Name << ") ] ";
}
ClapTrap &ClapTrap::operator= (const ClapTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	std::cout << "[ operator constructor called (CLAPTRAP : " << this->Name << ") ] ";
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "[ destructor called (CLAPTRAP : " << this->Name << ") ] ";
}

//	Others

void ClapTrap::attack(const std::string& target)
{
	if (canAct())
	{
		this->EP -= 1;
		std::cout << "> a wild " << target << " appeared!" << std::endl;
		std::cout << this->Name << " uses 'CLAP_ATTACK' on " << target << std::endl;
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
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HP > 0)
		std::cout << "" << this->Name << " is hit by 'GENERIC_ATTACK'" << std::endl;
	else
		std::cout << "" << this->Name << "'s lifeless carcass is hit by 'GENERIC_ATTACK'" << std::endl;
	this->HP -= amount;
	std::cout << "| HP : " << this->HP << " (-" << amount << ")" << std::endl << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (canAct())
	{
		std::cout << "" << this->Name << " uses 'GENERIC_HEAL'" << std::endl;
		this->EP -= 1;
		this->HP += amount;
		std::cout << "| HP : " << this->HP << " (+" << amount << ")" << std::endl;
		std::cout << "| EP : " << this->EP << " (-1)" << std::endl << std::endl;
	}
}

// ADDONS

bool ClapTrap::canAct(void)
{
	if (this->HP > 0 && this->EP > 0)
		return (true);
	else if (this->HP <= 0)
		std::cout << "" << this->Name << " is too dead to act..." << std::endl << "| HP : " << this->HP;
	else if (this->EP <= 0)
		std::cout << "" << this->Name << " is too tired to act..." << std::endl << "| EP : " << this->EP;
	else
		std::cout << "Huh???";
	std::cout << std::endl << std::endl;
	return (false);
}
bool ClapTrap::showStats(void)
{
	std::cout << "o-< " << this->Name << " STATS >-o" << std::endl;
	std::cout << "| HP : " << this->HP << std::endl;
	std::cout << "| EP : " << this->EP << std::endl;
	std::cout << "| AD : " << this->AD << std::endl << std::endl;

	return (false);
}