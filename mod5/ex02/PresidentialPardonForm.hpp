#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	protected:
		// Constructors
		PresidentialPardonForm();

	public:
		// Constructors - Destructor
		PresidentialPardonForm(const std::string _name);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator= (const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		// Others
		const std::string	getTarget(void) const;
		void				beExecuted(Bureaucrat const &b) const;
};

#endif //PRESIDENTIALPARDONFORM