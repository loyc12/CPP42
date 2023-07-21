#include "Cat.hpp"

// Constructors / Destructor

Cat::Cat()
{
	this->type = "cat";
	std::cout << "[ default constructor called (CAT) ] ";
}
Cat::Cat(const Cat &other)
{
	this->type = other.type;
	std::cout << "[ copy constructor called (CAT) ] ";
}
Cat &Cat::operator= (const Cat &other)
{
	this->type = other.type;
	std::cout << "[ operator constructor called (CAT) ] ";
	return *this;
}
Cat::~Cat()
{
	std::cout << "[ destructor called (CAT) ] ";
}

// Others

void	Cat::makeSound(void) const
{
	std::cout << "> meeeeeoowwwwwwwwwwwwwww ~" << std::endl;
}