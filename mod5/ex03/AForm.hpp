#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	name;
		bool		isSigned;
		int			signGrade;
		int			execGrade;

	protected:
		// Constructors
		AForm();

		// Setters
		void	setSignGrade(const int value);
		void	setExecGrade(const int value);
		void	setName(const std::string _name);

	public:
		// Constructors - Destructor
		AForm(const std::string _name, const int _signGrade, const int _execGrade);
		AForm(const AForm &other);
		AForm &operator= (const AForm &other);
		virtual ~AForm() = 0;

		// Setters - Getters
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		const std::string	getName(void) const;
		bool				canBeExec(void) const;

		// Others
		void			beSigned(Bureaucrat const &b);
		virtual void	beExecuted(Bureaucrat const &b) const;

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
					return "invalid grade : too low ( > sign/exec grade )";
				}
		};
		class FormUnsigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "invalid status : form unsigned";
				}
		};
};

std::ostream &operator<< (std::ostream &out, const AForm &rhs);

#endif //AFORM