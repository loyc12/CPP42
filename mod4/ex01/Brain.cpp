#include "Brain.hpp"

// Constructors / Destructor

Brain::Brain()
{
	for (int i = 0; i < BRAIN_SIZE; i++)
		this->ideas[i] = "";

	this->ideaCount = 0;

	std::cout << "[ default constructor called (BRAIN) ] ";
}
Brain::Brain(const Brain &other)
{
	for (int i = 0; i < other.ideaCount; i++)
		this->ideas[i] = other.ideas[i];

	this->ideaCount = other.ideaCount;

	std::cout << "[ copy constructor called (BRAIN) ] ";
}
Brain &Brain::operator= (const Brain &other)
{
	for (int i = 0; i < other.ideaCount; i++)
		this->ideas[i] = other.ideas[i];

	this->ideaCount = other.ideaCount;

	std::cout << "[ operator constructor called (BRAIN) ] ";
	return *this;
}
Brain::~Brain()
{
	std::cout << "[ destructor called (BRAIN) ] ";
}

// Others

void	Brain::addIdea(std::string idea)
{
	if (this->ideaCount < 100)
	{
		this->ideas[this->ideaCount] = idea;
		this->ideaCount++;
	}
	else
		std::cout << "unable to add a new idea; brain too full" << std::endl;
}
std::string	Brain::getIdea(int index)
{
	return (this->ideas[index]);
}