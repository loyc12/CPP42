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
}
PmergeMe::PmergeMe( IVEC &V, bool debug	)
{
	if ( debug ) { std::cout << "[ Called param. constr. for a PMERGEME instance ]\n"; }

	this->_debug = debug;
	this->_mode = VEC;
	this->_V = V;
	this->_L.clear();
}
PmergeMe::PmergeMe( ILST &L, bool debug )
{
	if ( debug ) { std::cout << "[ Called param. constr. for a PMERGEME instance ]\n"; }

	this->_debug = debug;
	this->_mode = LST;
	this->_V.clear();
	this->_L = L;
}

PmergeMe::~PmergeMe() { if ( this->_debug ) { std::cout << "[ Destroying a PMERGEME instance ]\n"; }}

PmergeMe::PmergeMe( const PmergeMe &other )
{
	if ( this->_debug ) { std::cout << "[ Called copy constr. for a PMERGEME instance ]\n"; }
	if ( this == &other ) { return; }

	this->_debug = other.debug();
	this->_V.clear();
	this->_L.clear();

	this->_mode = other.getMode();
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

// Sorters

void	PmergeMe::sort( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a container ] : "; }
	if ( this->_mode == VEC ) { this->sortVect(); }
	else if ( this->_mode == LST ) { this->sortList(); }

	else { std::cerr << "WARNING : mode has not been set, cannot sort\n"; }
}

void	PmergeMe::sortVect( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a vector ]\n"; }

std::sort( this->_V.begin(), this->_V.end() ); //					TODO : implement a custom sort
}

void	PmergeMe::sortList( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a list ]\n"; }
	this->_L.sort(); //													TODO : implement a custom sort
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
	for ( IVEC::const_iterator it = this->_V.begin(); it != this->_V.end(); it++ )
	{
		out << *it;
		if ( it != --( this->_V.end() )) { out << " "; }
	}
}

void	PmergeMe::writeList( std::ostream &out ) const
{
	if ( this->_debug ) { std::cout << "[ Writing a list ]\n"; }
	for ( ILST::const_iterator it = this->_L.begin(); it != this->_L.end(); it++ )
	{
		out << *it;
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