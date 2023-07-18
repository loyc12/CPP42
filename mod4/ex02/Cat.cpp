#include "Cat.hpp"

// Constructors / Destructor

Cat::Cat()
{
	this->type = "cat";
	this->brain = new Brain();

	std::cout << "[ default constructor called (CAT) ] ";
}
Cat::Cat(const Cat &other)
{
	this->type = other.type;
	*this->brain = *other.brain;

	std::cout << "[ copy constructor called (CAT) ] ";
}
Cat &Cat::operator= (const Cat &other)
{
	this->type = other.type;
	*this->brain = *other.brain;

	std::cout << "[ operator constructor called (CAT) ] ";
	return *this;
}
Cat::~Cat()
{
	delete this->brain;

	std::cout << "[ destructor called (CAT) ] ";
}

// Others

void	Cat::makeSound(void)
{
	std::cout << "> meeeeeoowwwwwwwwwwwwwww ~" << std::endl;
}
void	Cat::addIdea(std::string idea)
{
	this->brain->addIdea(idea);
}
std::string	Cat::getIdea(int index)
{
	return (this->brain->getIdea(index));
}