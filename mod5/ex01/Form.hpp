#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string	name;
		bool		isSigned;
		int			signGrade;
		int			execGrade;

		// Constructors
		Form();

		// Exceptions
		void	GradeTooHighException(void) const;
		void	GradeTooLowException(void) const;

		// Setters
		void	setSignGrade(int value);
		void	setExecGrade(int value);

	public:
		// Constructors - Destructor
		Form(std::string _name, int _signGrade, int _execGrade);
		Form(const Form &other);
		Form &operator= (const Form &other);
		~Form();

		// Setters - Getters
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		std::string	getName(void) const;

		// Others

		void		beSigned(Bureaucrat b);
};

std::ostream &operator<< (std::ostream &out, const Form &rhs);

#endif //FORM