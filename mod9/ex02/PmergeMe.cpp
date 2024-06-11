#include "PmergeMe.hpp"


// Constructors - Destructor

PmergeMe::PmergeMe(         ) { PmergeMe(    DFLT_DBG ); }
PmergeMe::PmergeMe( IVEC &V ) { PmergeMe( V, DFLT_DBG ); }
PmergeMe::PmergeMe( ILST &L ) { PmergeMe( L, DFLT_DBG ); }

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

	//this->checkVect();
}
PmergeMe::PmergeMe( ILST &L, bool debug )
{
	if ( debug ) { std::cout << "[ Called param. constr. for a PMERGEME instance ]\n"; }

	this->_debug = debug;
	this->_mode = LST;
	this->_V.clear();
	this->_L = L;
	this->_sortTime = 0;

	//this->checkList();
}

PmergeMe::~PmergeMe() { if_DBG { std::cout << "[ Destroying a PMERGEME instance ]\n"; }}

PmergeMe::PmergeMe( const PmergeMe &other )
{
	if_DBG { std::cout << "[ Called copy constr. for a PMERGEME instance ]\n"; }
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
	if_DBG { std::cout << "[ Called assign. oper. for a PMERGEME instance ]\n"; }
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
	timeval start, end;
	int maxCmp = 0;

	if_DBG { std::cout << "\nSorting "; }
	if   ( this->_mode == VEC )
	{
		gettimeofday( &start, NULL );
		maxCmp = this->sortVect();
		gettimeofday( &end, NULL );
	}
	elif ( this->_mode == LST )
	{
		gettimeofday( &start, NULL );
		maxCmp = this->sortList();
		gettimeofday( &end, NULL );
	}
	else { std::cerr << "WARNING : mode has not been set, cannot sort\n"; return; }

	this->_sortTime = (( end.tv_sec  - start.tv_sec ) * 1000000 ) + end.tv_usec - start.tv_usec;

	if_DBG { std::cout << "\nSorted within " << this->_sortTime << " microseconds\n"; }
	if_DBG { std::cout << "Sorted within " << maxCmp << " comparisons\n"; } // WARNING : assumes worst case comparisons
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
	if ( this->_V.empty() ) { out << "Empty vector"; return; }
	size_t i = 0;
	for ( IVEC::const_iterator it = this->_V.begin(); it != this->_V.end(); it++ )
	{
		i++;

		// skips the middle numbers if there are more than 2 * DSPL_MAX numbers
		if ( !this->_debug && i >= 1 + DSPL_MAX && i < 1 + this->_V.size() - DSPL_MAX )
			if ( i == 1 + DSPL_MAX ) out << "...";  else continue;
		else out << *it;

		if ( it != --( this->_V.end() )) { out << " "; }
	}
}

void	PmergeMe::writeList( std::ostream &out ) const
{
	if ( this->_L.empty() ) { out << "Empty list"; return; }
	size_t i = 0;
	for ( ILST::const_iterator it = this->_L.begin(); it != this->_L.end(); it++ )
	{
		i++;

		// skips the middle numbers if there are more than 2 * DSPL_MAX numbers
		if ( !this->_debug && i >= 1 + DSPL_MAX && i < 1 + this->_L.size() - DSPL_MAX )
			if ( i == 1 + DSPL_MAX ) out << "...";  else continue;
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