#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

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
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator= (const Bureaucrat &other);
		~Bureaucrat();

		// Setters - Getters
		int					getGrade(void) const;
		const std::string	getName(void) const;
		void				promote(void);
		void				demote(void);

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