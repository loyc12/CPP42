#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define XCPT public: const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>


// CLASS PMERGEME ( implemented in .cpp file )
class PmergeMe
{
	private:
		// Attributes
		std::string	name;

	protected:
		// Checkers
		void checkName( const std::string _name ) const;

		// Nested Classes
		class BadName : public std::exception { XCPT { return "PmergeMe error : invalid name, idiot!"; } };

	public:
		// Constructors - Destructor
		PmergeMe();
		PmergeMe( const std::string _name );
		PmergeMe( const PmergeMe &other );
		~PmergeMe();

		// Operators
		PmergeMe &operator= ( const PmergeMe &other );

		// Setters - Getters
		void				setName( const std::string _name );
		const std::string	getName( void ) const;

		// Others
		void	printName( void ) const;

};

std::ostream &operator<< (std::ostream &out, const PmergeMe &rhs);

#endif // PMERGEME_HPP