#include "PmergeMe.hpp"


// Constructors - Destructor

PmergeMe::PmergeMe(         ) { PmergeMe(    DEBUG_DEFAULT ); }
PmergeMe::PmergeMe( IVEC &V ) { PmergeMe( V, DEBUG_DEFAULT ); }
PmergeMe::PmergeMe( ILST &L ) { PmergeMe( L, DEBUG_DEFAULT ); }

PmergeMe::PmergeMe( bool debug )
{
	if ( debug ) { std::cout << "[ Called def. constr. for a PMERGEME instance ]\n"; }

	this->_debug = debug;
	this->_mode = NUL;
	this->_V.clear();
	this->_L.clear();
	this->_sortTime = 0;
}
PmergeMe::PmergeMe( IVEC &V, bool debug	)
{
	if ( debug ) { std::cout << "[ Called param. constr. for a PMERGEME instance ]\n"; }

	this->_debug = debug;
	this->_mode = VEC;
	this->_V = V;
	this->_L.clear();
	this->_sortTime = 0;
}
PmergeMe::PmergeMe( ILST &L, bool debug )
{
	if ( debug ) { std::cout << "[ Called param. constr. for a PMERGEME instance ]\n"; }

	this->_debug = debug;
	this->_mode = LST;
	this->_V.clear();
	this->_L = L;
	this->_sortTime = 0;
}

PmergeMe::~PmergeMe() { if ( this->_debug ) { std::cout << "[ Destroying a PMERGEME instance ]\n"; }}

PmergeMe::PmergeMe( const PmergeMe &other )
{
	if ( this->_debug ) { std::cout << "[ Called copy constr. for a PMERGEME instance ]\n"; }
	if ( this == &other ) { return; }

	this->_debug = other.debug();
	this->_sortTime = other.getSortTime();
	this->_mode = other.getMode();
	this->_V.clear();
	this->_L.clear();

	if   ( this->_mode == VEC ) { this->_V = other.getVect(); }
	elif ( this->_mode == LST ) { this->_L = other.getList(); }
}

// Operators

PmergeMe &PmergeMe::operator= ( const PmergeMe &other )
{
	if ( this->_debug ) { std::cout << "[ Called assign. oper. for a PMERGEME instance ]\n"; }
	if ( this == &other ) { return *this; }

	this->_debug = other.debug();
	this->_V.clear();
	this->_L.clear();
	this->_sortTime = other.getSortTime();

	this->_mode = other.getMode();
	if   ( this->_mode == VEC ) { this->_V = other.getVect(); }
	elif ( this->_mode == LST ) { this->_L = other.getList(); }

	return *this;
}

// Setters

void	PmergeMe::debug( bool debug ) { this->_debug = debug; }

// Getters

bool	PmergeMe::debug(   void ) const { return this->_debug; }
int		PmergeMe::getMode( void ) const { return this->_mode; }
IVEC	PmergeMe::getVect( void ) const { return this->_V; }
ILST	PmergeMe::getList( void ) const { return this->_L; }
time_t	PmergeMe::getSortTime(  ) const { return this->_sortTime; }

// Sorters

void	PmergeMe::sort( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a container ] : "; }

	timeval start, end;

	if   ( this->_mode == VEC )
	{
		gettimeofday( &start, NULL );
		this->sortVect();
		gettimeofday( &end, NULL );
	}
	elif ( this->_mode == LST )
	{
		gettimeofday( &start, NULL );
		this->sortList();
		gettimeofday( &end, NULL );
	}

	else { std::cerr << "WARNING : mode has not been set, cannot sort\n"; return; }

	// Calculating time
	long s  = end.tv_sec  - start.tv_sec;
	long us = end.tv_usec - start.tv_usec;
	this->_sortTime = ( s * 1000000 ) + us;

	if ( this->_debug ) { std::cout << "done in " << this->_sortTime << "us\n"; }
}

void	PmergeMe::sortVect( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a vector ]\n"; }
	std::sort( this->_V.begin(), this->_V.end() ); //					TODO : implement a custom sort
}

void	PmergeMe::sortList( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a list ]\n"; }
	this->_L.sort(); //												TODO : implement a custom sort
}

// Printers

void	PmergeMe::writeOut( void ) const
{
	if   ( this->_mode == VEC ) { this->writeVect( std::cout ); }
	elif ( this->_mode == LST ) { this->writeList( std::cout ); }

	else { std::cerr << "WARNING : mode has not been set, cannot print\n"; }
	std::cout << std::endl;
}

void	PmergeMe::writeVect( std::ostream &out ) const
{
	if ( this->_debug ) { std::cout << "[ Writing a vector ]\n"; }
	if ( this->_V.empty() ) { out << "Empty vector"; return; }
	unsigned long i = 0;
	for ( IVEC::const_iterator it = this->_V.begin(); it != this->_V.end(); it++ )
	{
		i++;

		// skips the middle numbers if there are more than 2 * DISPLAY_HALF_MAX numbers
		if ( !this->_debug && i >= 1 + DISPLAY_HALF_MAX && i < 1 + this->_V.size() - DISPLAY_HALF_MAX )
			if ( i == 1 + DISPLAY_HALF_MAX ) out << "...";  else continue;
		else out << *it;

		if ( it != --( this->_V.end() )) { out << " "; }
	}
}

void	PmergeMe::writeList( std::ostream &out ) const
{
	if ( this->_debug ) { std::cout << "[ Writing a list ]\n"; }
	if ( this->_L.empty() ) { out << "Empty list"; return; }
	unsigned long i = 0;
	for ( ILST::const_iterator it = this->_L.begin(); it != this->_L.end(); it++ )
	{
		i++;

		// skips the middle numbers if there are more than 2 * DISPLAY_HALF_MAX numbers
		if ( !this->_debug && i >= 1 + DISPLAY_HALF_MAX && i < 1 + this->_L.size() - DISPLAY_HALF_MAX )
			if ( i == 1 + DISPLAY_HALF_MAX ) out << "...";  else continue;
		else out << *it;

		if ( it != --( this->_L.end() )) { out << " "; }
	}
}

std::ostream &operator<< (std::ostream &out, const PmergeMe &rhs)
{
	if   ( rhs.getMode() == VEC ) { rhs.writeVect( out ); }
	elif ( rhs.getMode() == LST ) { rhs.writeList( out ); }

	else { out << "WARNING : mode has not been set, cannot print\n"; }
	return ( out );
}