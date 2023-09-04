#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

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
		void	setSignGrade(const int value);
		void	setExecGrade(const int value);

	public:
		// Constructors - Destructor
		Form(const std::string _name, const int _signGrade, const int _execGrade);
		Form(const Form &other);
		Form &operator= (const Form &other);
		~Form();

		// Setters - Getters
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		const std::string	getName(void) const;

		// Others
		void	beSigned(Bureaucrat const &b);

		// Nested Classes
		class GradeTooHigh : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "invalid grade : too high ( < 1 )";
				}
		};
		class GradeTooLow : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "invalid grade : too low ( > sign\\exec grade )";
				}
		};
};

std::ostream &operator<< (std::ostream &out, const Form &rhs);

#endif //FORM