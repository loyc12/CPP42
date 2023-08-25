#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <unistd.h>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;

	protected:
		// Constructors
		RobotomyRequestForm();

	public:
		// Constructors - Destructor
		RobotomyRequestForm(const std::string _name);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator= (const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		// Others
		const std::string	getTarget(void) const;
		void				beExecuted(Bureaucrat const &b) const;
};

#endif //ROBOTOMYREQUESTFORM