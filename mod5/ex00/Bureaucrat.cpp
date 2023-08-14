#include "Bureaucrat.hpp"

// Constructors - Destructor

Bureaucrat::Bureaucrat()
{
	//throw "invalid call : default bureaucrat constructor"; //	alternative to implementing this constructor in private

	std::cout << "Called default constructor (BUREAUCRAT)" << std::endl;

	this->grade = 150;
	this->name = "UNINITIALIZED";

	std::cout << "Constructed bureaucrat : " << this->name << " ( grade " << this->grade << " )" << std::endl;
}
Bureaucrat::Bureaucrat(std::string _name, int _grade)
{
	std::cout << "Called parameterized constructor (BUREAUCRAT)" << std::endl;

	this->grade = 150;
	this->name = _name;
	this->setGrade(_grade);

	std::cout << "Constructed bureaucrat : " << this->name << " ( grade " << this->grade << " )" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "Called copy constructor (BUREAUCRAT)" << std::endl;

	this->grade = 150;
	this->name = other.getName();
	this->setGrade(other.getGrade());

	std::cout << "Copied bureaucrat : " << this->name << " ( grade " << this->grade << " )" << std::endl;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &other)
{
	std::cout << "Called assignment operator (BUREAUCRAT)" << std::endl;

	this->name = other.getName();
	this->setGrade(other.getGrade());

	std::cout << "Copied bureaucrat : " << this->name << " ( grade " << this->grade << " )" << std::endl;

	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroying bureaucrat : " << this->name << " ( grade " << this->grade << " )" << std::endl;
}

// Exceptions

void Bureaucrat::GradeTooHighException(void) const
{
	//TODO : CREATE A SUBCLASS OF std::exception WHERE what() RETURNS THIS STRING :
	throw "invalid grade : too high ( < 1 )";
}
void Bureaucrat::GradeTooLowException(void) const
{
	//TODO : CREATE A SUBCLASS OF std::exception WHERE what() RETURNS THIS STRING :
	throw "invalid grade : too low ( > 150 )";
}

// Setters - Getters

void	Bureaucrat::setGrade(int value)
{
	if (value < 1)
		this->GradeTooHighException();
	else if (value > 150)
		this->GradeTooLowException();
	else
		this->grade = value;
}
int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}
std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::promote(void)
{
	this->setGrade(this->getGrade() - 1);
	std::cout << "Promoted bureaucrat " << this->name << " to grade " << this->grade << std::endl;
}
void	Bureaucrat::demote(void)
{
	this->setGrade(this->getGrade() + 1);
	std::cout << "Demoted bureaucrat " << this->name << " to grade " << this->grade << std::endl;
}

// Others

std::ostream &operator<< (std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << " ( grade " << rhs.getGrade() << " bureaucrat )";
	return (out);
}