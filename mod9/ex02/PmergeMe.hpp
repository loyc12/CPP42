#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define XCPT public: const char *what() const throw()
# define if_DBG if ( this->_debug )
# define elif else if
# define DFLT_DBG false
# define DSPL_MAX 64 // half the max number of elements to display

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
# define IVIT std::vector< int >::iterator

# define PVEC std::vector< std::pair< int, int > >
# define PVIT std::vector< std::pair< int, int > >::iterator

# define ILST std::list< int >
# define ILIT std::list< int >::iterator

# define PLST std::list< std::pair< int, int > >
# define PLIT std::list< std::pair< int, int > >::iterator

# define PAIR std::pair< int, int >

// time
# include <sys/time.h>

// Modes
# define NUL 0
# define VEC 1
# define LST 2

// Jacobstal sequence ( from index 2 of OEIS A001045 )
# define JNUM { 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, \
		2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, \
		699051, 1398101, 2796203, 5592405, 11184811, 22369621, \
		44739243, 89478485, 178956971, 357913941, 715827883 }

// Jacobstal difference sequence ( based on above's sequence )
# define JDIF { 2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, \
		2730, 5462, 10922, 21846, 43690, 87382, 174762, 349526, \
		699050, 1398102, 2796202, 5592406, 11184810, 22369622, \
		44739242, 89478486, 178956970, 357913942, 715827882, \
		1431655766 }


// idea : make it a single class with a single container,
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
		class BadValues : public std::exception { XCPT { return "Input error : invalid value(s)"; } };

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

		// Checkers
		//void	checkVect( void );
		//void	checkList( void );

		// Printers
		void	writeOut( void ) const;
		void	writeVect( std::ostream &out ) const;
		void	writeList( std::ostream &out ) const;

};

std::ostream &operator<< (std::ostream &out, const PmergeMe &rhs);

// Addons

void	printPVect( PVEC &pV, int hr, int r );
int		takeLast( IVEC &V );
int		takeFirst( IVEC &V );
PAIR	makePair( IVEC &V );
int		insertPair( PVEC &pv, PAIR p, bool debug );
int		insertValue( IVEC &V, IVIT max_it, int val, bool debug );

void	printPList( PLST &pL, int hr, int r );
int		takeLast( ILST &L );
int		takeFirst( ILST &L );
PAIR	makePair( ILST &L );
int		insertPair( PLST &pL, PAIR p, bool debug );
int		insertValue( ILST &L, ILIT max_it, int val, bool debug );

#endif // PMERGEME_HPP