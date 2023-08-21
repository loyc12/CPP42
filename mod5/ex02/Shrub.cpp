#include "Shrub.hpp"

// Constructors - Destructor

Shrub::Shrub()
{
	std::cout << "Called default constructor (SHRUB) ";
}
Shrub::Shrub(const int pos)
{
	std::cout << "Called parameterized constructor (SHRUB) ";
}
Shrub::Shrub(const Shrub &other)
{
	std::cout << "Called copy constructor (SHRUB) ";
}
Shrub &Shrub::operator= (const Shrub &other)
{
	std::cout << "Called assignment operator (SHRUB) ";

	return *this;
}
Shrub::~Shrub()
{
	std::cout << "Called Destructor (SHRUB) ";
}

// Setters - Getters

// Others

std::ostream &operator<< (std::ostream &out, const Shrub &rhs)
{
	out << "a simple shrub";
	return (out);
}