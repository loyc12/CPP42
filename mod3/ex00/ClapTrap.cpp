#include "ClapTrap.hpp"

// Constructors / Destructor

ClapTrap::ClapTrap()
{
	this->HP = 10;
	this->EP = 10;
	this->AD = 0;
	std::cout << "[ default constructor called ] ";
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	std::cout << "[ copy constructor called ] ";
}
ClapTrap &ClapTrap::operator= (const ClapTrap &other)
{
	this->HP = other.HP;
	this->EP = other.EP;
	this->AD = other.AD;
	std::cout << "[ operator constructor called ] ";
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "[ destructor called ] ";
}

//	Others

void ClapTrap::attack(const std::string& target)
{
	if (canAct())
	{
		this->EP -= 1;
		std::cout << "a wild " << target << " appeared!" << std::endl;
		std::cout << "CLAPTRAP uses 'ATTACK'" << std::endl;
		if (this->AD > 0)
			std::cout << "it was super effective ( -" << this->AD << " HP )" << std::endl;
		else if (this->AD == 0)
			std::cout << "it wasn't very effective ( -0 HP )" << std::endl;
		else
			std::cout << "you're just healing now wth ( +" << -this->AD << " HP )" << std::endl;
//  	deal actual damage here
//		std::cout << target << " now has N/A HP" << std::endl << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HP > 0)
		std::cout << "CLAPTRAP receives GENERIC_DAMAGE ( -" << amount << " HP )" << std::endl;
	else
		std::cout << "CLAPTRAP's lifeless carcass receives GENERIC_DAMGE ( -" << amount << " HP )" << std::endl;
	this->HP -= amount;
	std::cout << "CLAPTRAP now has " << this->HP << " HP" << std::endl << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (canAct())
	{
		std::cout << "CLAPTRAP uses 'REPAIR' ( +" << amount << " HP )" << std::endl;
		this->EP -= 1;
		this->HP += amount;
		std::cout << "CLAPTRAP now has " << this->HP << " HP" << std::endl << std::endl;
	}
}

bool ClapTrap::canAct(void)
{
	if (this->HP > 0 && this->EP > 0)
		return (true);
	else if (this->HP <= 0)
		std::cout << "ClapTrap is too dead to act";
	else if (this->EP <= 0)
		std::cout << "ClapTrap is too tired to act";
	else
		std::cout << "Huh???";
	std::cout << std::endl << std::endl;
	return (false);
}
bool ClapTrap::showStats(void)
{
	std::cout << "CLATRAP STATS " << std::endl;
	std::cout << "| HP : " << this->HP << std::endl;
	std::cout << "| EP : " << this->EP << std::endl;
	std::cout << "| AD : " << this->AD << std::endl << std::endl;

	return (false);
}