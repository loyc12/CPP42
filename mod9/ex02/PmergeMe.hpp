#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define XCPT public: const char *what() const throw()
# define elif else if
# define DEBUG_DEFAULT false
# define DISPLAY_HALF_MAX 8 // half the max number of elements to display

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <utility>
# include <sstream>
# include <string>

// containers
# include <vector>
# include <list>
# define IVEC std::vector< int >
# define ILST std::list< int >

// time
# include <sys/time.h>

// Modes
# define NUL 0
# define VEC 1
# define LST 2

// make it a single class with a single container,
// but use different functions for each container type needed

class PmergeMe
{
	private:
		// Attributes
		int 	_mode;
		bool	_debug;
		IVEC	_V;
		ILST	_L;
		double _sortTime;

		// Constructors
		PmergeMe();
		PmergeMe( bool debug );

		// Sorters
		int	sortVect( void );
		int	sortList( void );

	protected:
		// Nested Classes
		class BadSort : public std::exception { XCPT { return "PmergeMe error : TemplateError ( dumbass, change it... )"; } };

	public:
		// Constructors - Destructor
		PmergeMe( IVEC &V );
		PmergeMe( ILST &L );

		PmergeMe( IVEC &V, bool debug );
		PmergeMe( ILST &L, bool debug );

		~PmergeMe();
		PmergeMe( const PmergeMe &other );

		// Operators
		PmergeMe &operator= ( const PmergeMe &other );

		// Setters
		void	debug( bool debug );

		// Getters
		bool	debug(   void ) const;
		int		getMode( void ) const;
		IVEC	getVect( void ) const;
		ILST	getList( void ) const;
		time_t	getSortTime() const;

		// Sorters
		void 	sort( void );

		// Printers
		void	writeOut( void ) const;
		void	writeVect( std::ostream &out ) const;
		void	writeList( std::ostream &out ) const;

};

std::ostream &operator<< (std::ostream &out, const PmergeMe &rhs);

#endif // PMERGEME_HPP