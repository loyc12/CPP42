#include "Shrub.hpp"

// Constructors - Destructor

Shrub::Shrub()
{
	std::cout << "Called default constructor (SHRUB) ";
}
Shrub::Shrub(ShrubberyCreationForm *_scf, int _h_pos)
{
	std::cout << "Called parameterized constructor (SHRUB) ";
	this->scf = _scf;
	this->horizontal_p = _h_pos;
}
Shrub::Shrub(const Shrub &other)
{
	std::cout << "Called copy constructor (SHRUB) ";
	this->horizontal_p = other.horizontal_p;
	this->scf = other.scf;
}
Shrub &Shrub::operator= (const Shrub &other)
{
	std::cout << "Called assignment operator (SHRUB) ";
	this->horizontal_p = other.horizontal_p;
	this->scf = other.scf;

	return *this;
}
Shrub::~Shrub()
{
	std::cout << "Called Destructor (SHRUB) ";
}

// Others

int	Shrub::getPos(void) const
{
	return (this->horizontal_p);
}

std::ostream &operator<< (std::ostream &out, const Shrub &rhs)
{
	out << rhs.getPos();
	return (out);
}

// Shrubbers