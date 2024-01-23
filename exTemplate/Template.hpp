#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

class Template
{
	private:
		// Attributes
		std::string	name;

	protected:
		// Nested Classes
		class BadName : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "invalid name : get reck'd, dweeb!"; }
		};

	public:
		// Constructors - Destructor
		Template();
		Template( const std::string _name );
		Template( const Template &other );
		~Template();
		Template &operator= ( const Template &other );

		// Setters - Getters
		void				setName( const std::string _name );
		const std::string	getName( void ) const;

		// Others
		void	printName( void );

};

std::ostream &operator<< (std::ostream &out, const Template &rhs);

#endif // TEMPLATE_HPP