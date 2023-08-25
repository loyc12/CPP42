#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Intern.hpp"
# include "AForm.hpp"

class Intern
{
	public:
		int	number;
		Intern();
		// Constructors - Destructor
		Intern(const Intern &other);
		Intern &operator= (const Intern &other);
		~Intern();

		// Others
		AForm	*makeForm(std::string _formName, std::string _targetName) const;
};

std::ostream &operator<< (std::ostream &out, const Intern &rhs);

#endif //INTERN