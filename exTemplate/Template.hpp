#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>


// CLASS ( implemented in .cpp file )


class Template
{
	private:
		// Attributes
		std::string	name;

	protected:
		// Checkers
		void checkName( const std::string _name) const;

		// Nested Classes
		class BadName : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Template error : invalid name, idiot!"; }
		};

	public:
		// Constructors - Destructor
		Template();
		Template( const std::string _name );
		Template( const Template &other );
		~Template();

		// Operators
		Template &operator= ( const Template &other );

		// Setters - Getters
		void				setName( const std::string _name );
		const std::string	getName( void ) const;

		// Others
		void	printName( void );

};

std::ostream &operator<< (std::ostream &out, const Template &rhs);


// CLASS TEMPLATE ( implemented in .tpp file )


template <class T>
class Template_T
{
	private:
		// Attributes
		T	value;

	protected:
		// Checkers
		void	checkValue( const T _value ) const;

		// Nested Classes
		class BadValue : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Template_T error : invalid value, dumbass!"; }
		};

	public:
		// Constructors - Destructor
		Template_T();
		Template_T( const T _value );
		Template_T( const Template_T<T> &other );
		~Template_T();

		// Operators
		Template_T<T> &operator= ( const Template_T<T> &other );

		// Setters - Getters
		void	setValue( const T _value );
		const T	getValue( void ) const;

		// Others
		void	printValue( void );

};
template < typename T >
std::ostream &operator<< (std::ostream &out, const Template_T<T> &rhs);

# include "Template.tpp"

#endif // TEMPLATE_HPP