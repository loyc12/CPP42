#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		int	number;

	public:
		// Constructors - Destructor
		Intern();
		Intern(const Intern &other);
		Intern &operator= (const Intern &other);
		~Intern();

		// Others
		int		getNumber(void) const;
		int		findFormID(std::string _formName) const;
		AForm	*makeForm(std::string _formName, std::string _targetName) const;

		// Nested Classes
		class InvalidFormName : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "invalid form name";
				}
		};
};

std::ostream &operator<< (std::ostream &out, const Intern &rhs);

#endif //INTERN