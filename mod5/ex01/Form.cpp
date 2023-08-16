#include "Form.hpp"

// Constructors - Destructor

Form::Form()
{
	//throw "invalid call : default form constructor"; //	alternative to implementing this constructor in private

	std::cout << "Called default constructor (FORM)" << std::endl;

	this->isSigned = false;
	this->signGrade = 150;
	this->execGrade = 150;
	this->name = "UNINITIALIZED";

	std::cout << "Constructed form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;
}
Form::Form(const std::string _name, const int _signGrade, const int _execGrade)
{
	std::cout << "Called parameterized constructor (FORM)" << std::endl;

	this->isSigned = false;
	this->signGrade = 150;
	this->execGrade = 150;
	this->setSignGrade(_signGrade);
	this->setExecGrade(_execGrade);
	this->name = _name;

	std::cout << "Constructed form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;
}
Form::Form(const Form &other)
{
	std::cout << "Called copy constructor (FORM)" << std::endl;

	this->isSigned = false;
	this->signGrade = 150;
	this->execGrade = 150;
	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->name = other.getName();

	std::cout << "Copied form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;
}

Form &Form::operator= (const Form &other)
{
	std::cout << "Called assignment operator (FORM)" << std::endl;

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->name = other.getName();

	std::cout << "Copied form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;

	return *this;
}

Form::~Form()
{
	std::cout << "Destroying form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;
}

// Exceptions

void Form::GradeTooHighException(void) const
{
	throw GradeTooHigh();
}
void Form::GradeTooLowException(void) const
{
	throw GradeTooLow();
}

// Setters - Getters

void	Form::setSignGrade(const int value)
{
	if (value < 1)
		this->GradeTooHighException();
	else if (value > 150)
		this->GradeTooLowException();
	else
		this->signGrade = value;
}
void	Form::setExecGrade(const int value)
{
	if (value < 1)
		this->GradeTooHighException();
	else if (value > 150)
		this->GradeTooLowException();
	else
		this->execGrade = value;
}
int	Form::getSignGrade(void) const
{
	return (this->signGrade);
}
int	Form::getExecGrade(void) const
{
	return (this->execGrade);
}
const std::string	Form::getName(void) const
{
	return (this->name);
}

// Others

void	Form::beSigned(Bureaucrat const &b)
{
	if (this->getSignGrade() < b.getGrade())
		this->GradeTooLowException();
	else
		this->isSigned = true;
}

std::ostream &operator<< (std::ostream &out, const Form &rhs)
{
	out << rhs.getName() << " ( sign/exec form of grade " << rhs.getSignGrade()<< "/" << rhs.getExecGrade() << " )";
	return (out);
}