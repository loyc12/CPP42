#include "RobotomyRequestForm.hpp"

// Constructors - Destructor

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Called default constructor (R.R.FORM) ";

	this->setSignGrade(72);
	this->setExecGrade(45);
	this->setName("Robotomy Request");
	this->target = "UNINITIALIZED";
}
RobotomyRequestForm::RobotomyRequestForm(const std::string _target)
{
	std::cout << "Called parameterized constructor (R.R.FORM) ";

	this->setSignGrade(72);
	this->setExecGrade(45);
	this->setName("Robotomy Request");
	this->target = _target;

	std::cout << "Constructed robotomy request form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	std::cout << "Called copy constructor (R.R.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

	std::cout << "Copied robotomy request form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &other)
{
	std::cout << "Called assignment operator (R.R.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

	std::cout << "Copied robotomy request form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;

	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destroying robotomy request form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " ) ";
}

// Others

const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}
void	RobotomyRequestForm::beExecuted(Bureaucrat const &b) const
{
	if (!this->canBeExec())
		throw FormUnsigned();
	else if (this->getExecGrade() < b.getGrade())
		throw GradeTooLow();
	else if (rand() % 2)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << "'s robotomy has failed" << std::endl;
}