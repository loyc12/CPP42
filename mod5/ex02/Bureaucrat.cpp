#include "Bureaucrat.hpp"

// Constructors - Destructor

Bureaucrat::Bureaucrat()
{
	std::cout << "Called default constructor (BUREAUCRAT) ";

	this->grade = 150;
	this->name = "UNINITIALIZED";
}
Bureaucrat::Bureaucrat(std::string _name, int _grade)
{
	std::cout << "Called parameterized constructor (BUREAUCRAT) ";

	this->grade = 150;
	this->name = _name;
	this->setGrade(_grade);

	std::cout << "Constructed bureaucrat : " << this->name << " ( grade " << this->grade << " )" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "Called copy constructor (BUREAUCRAT) ";

	this->grade = 150;
	this->name = other.getName();
	this->setGrade(other.getGrade());

	std::cout << "Copied bureaucrat : " << this->name << " ( grade " << this->grade << " )" << std::endl;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &other)
{
	std::cout << "Called assignment operator (BUREAUCRAT) ";

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
	throw GradeTooHigh();
}
void Bureaucrat::GradeTooLowException(void) const
{
	throw GradeTooLow();
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
const std::string	Bureaucrat::getName(void) const
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

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << " signed the form " << f.getName() << " successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << this->getName() << " couldn't sign the form " << f.getName() << " because of error : " << e.what() << std::endl;
	}
}
void	Bureaucrat::executeForm(const AForm &f)
{
	try
	{
		f.beExecuted(*this);
		std::cout << "Bureaucrat " << this->getName() << " executed the form " << f.getName() << " successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << this->getName() << " couldn't execute the form " << f.getName() << " because of error : " << e.what() << std::endl;
	}
}

std::ostream &operator<< (std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << " ( grade " << rhs.getGrade() << " bureaucrat )";
	return (out);
}