#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string	name;
		int			grade;

	protected:
		// Constructors
		Bureaucrat();

		// Setters
		void	setGrade(int value);

	public:
		// Constructors - Destructor
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator= (const Bureaucrat &other);
		~Bureaucrat();

		// Setters - Getters
		int					getGrade(void) const;
		const std::string	getName(void) const;
		void				promote(void);
		void				demote(void);

		// Others
		void	signForm(AForm &f);
		void	executeForm(AForm const &f);

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
					return "invalid grade : too low ( > 150 )";
				}
		};
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &rhs);

#endif //BUREAUCRAT