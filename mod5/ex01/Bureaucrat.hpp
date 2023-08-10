#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string	name;
		int			grade;

		// Constructors
		Bureaucrat();

		// Exceptions
		void	GradeTooHighException(void) const;
		void	GradeTooLowException(void) const;

		// Setters
		void	setGrade(int value);

	public:
		// Constructors - Destructor
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator= (const Bureaucrat &other);
		~Bureaucrat();

		// Setters - Getters
		int			getGrade(void) const;
		std::string	getName(void) const;
		void		promote(void);
		void		demote(void);

		// Others
		void	signForm(Form *f);
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &rhs);

#endif //BUREAUCRAT