#include "PmergeMe.hpp"

#define PVEC std::vector< std::pair< int, int > >
#define PLST std::list< std::pair< int, int > >
#define PAIR std::pair< int, int >

// Jacobstal sequence ( fomr index 1 of OEIS A001045 )
#define JNUM { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, \
		2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, \
		699051, 1398101, 2796203, 5592405, 11184811, 22369621, \
		44739243, 89478485, 178956971, 357913941, 715827883 } \

// TODO : use jacobstal to reinsert the last number from pair into the "array" of numbers (in order)

// Debug printers

void	printPVect( PVEC &pV, bool hr, int r )
{
	if ( pV.empty() ) { std::cout << "\nEmpty pair vector" << std::endl; return; }
	std::cout << std::endl;

	for ( PVEC::const_iterator it = pV.begin(); it != pV.end(); it++ )
	{ std::cout << "[ " << it->first << " " << it->second << " ]\n"; }

	if ( hr ) { std::cout << "( " << r << " )\n\n"; }
	std::cout << std::endl;
}

void	printPList( PLST &pL, bool hr, int r )
{
	if ( pL.empty() ) { std::cout << "\nEmpty pair list" << std::endl; return; }
	std::cout << std::endl;

	for ( PLST::const_iterator it = pL.begin(); it != pL.end(); it++ )
	{ std::cout << "[ " << it->first << " " << it->second << " ]\n"; }

	if ( hr ) { std::cout << "( " << r << " )\n\n"; }
	std::cout << std::endl;
}

int takeLast( IVEC &V )
{
	int i = V.back();
	V.pop_back();
	return i;
}
int takeFirst( IVEC &V )
{
	int i = V.front();
	V.erase( V.begin() );
	return i;
}
int takeLast( ILST &L )
{
	int i = L.back();
	L.pop_back();
	return i;
}
int takeFirst( ILST &L )
{
	int i = L.front();
	L.pop_front();
	return i;
}

PAIR makePair( IVEC &V )
{
	PAIR p;
	if   ( V.front() <= V.back() ) { p = PAIR( V.front(), V.back() ); }
	else { p = PAIR( V.back(), V.front() ); }
	V.erase( V.begin() );
	V.pop_back();
	return p;
}
PAIR makePair( ILST &L )
{
	PAIR p;
	if   ( L.front() <= L.back() ) { p = PAIR( L.front(), L.back() ); }
	else { p = PAIR( L.back(), L.front() ); }
	L.pop_front();
	L.pop_back();
	return p;
}

int insertPair( PVEC &pV, PAIR p )
{

	if ( pV.empty() ) { pV.push_back( p ); return 0; }
	if ( pV.size() == 1 )
	{
		if ( p.first <= pV.front().first ) { pV.insert( pV.begin(), p ); }
		else { pV.push_back( p ); }
		return 1;
	}

	PVEC::iterator it = pV.begin() + pV.size() / 2;
	int cmpCount = 0;
	int dir = ( p.first <= it->first ) ? -1 : 1;

	if ( dir == -1 ) { while ( it != pV.begin() && p.first < it->first )
	{
		it--;
		cmpCount++;
	}}
	else { while ( it != pV.end() && p.first > it->first )
	{
		it++;
		cmpCount++;
	}}

	pV.insert( it, p );

	return cmpCount;
}
int insertPair( PLST &pL, PAIR p )
{

	if ( pL.empty() ) { pL.push_back( p ); return 0; }
	if ( pL.size() == 1 )
	{
		if ( p.first <= pL.front().first ) { pL.push_front( p ); }
		else { pL.push_back( p ); }
		return 1;
	}

	PLST::iterator it = pL.begin();
	int cmpCount = 0;
	int dir = ( p.first <= it->first ) ? -1 : 1;

	if ( dir == -1 ) { while ( it != pL.end() && p.first < it->first )
	{
		it++;
		cmpCount++;
	}}
	else { while ( it != pL.begin() && p.first > it->first )
	{
		it--;
		cmpCount++;
	}}

	pL.insert( it, p );

	return cmpCount;
}

int insertVal( IVEC &V, int val )
{
	int jnum[] = JNUM;
	int cmpCount = 0;
	int i = 1;
	int j = 1;

	if ( V.empty() ) { V.push_back( val ); return 0; }

	IVEC::iterator it = V.end();
	std::advance( it, -jnum[ j ] );

	while ( it != V.begin() )
	{
		it++;
		if ( i ==  jnum[ j - 1 ])
		{
			i =  jnum[ j++ ];
			if (( size_t )i > V.size() ) { i = V.size(); }
			it = V.end();
			std::advance( it, -i );
		}
		cmpCount++;
		if ( val < *it )
			break;
		i++;
	}

	V.insert( it, val );

	return cmpCount;
}
int insertVal( ILST &L, int val )
{
	int jnum[] = JNUM;
	int cmpCount = 0;
	int i = 0;
	int j = 0;

	ILST::iterator it = L.begin();

	while ( it != L.end() )
	{
		if ( i == jnum[ j - 1 ])
		{
			i = jnum[ j++ ];
			it = L.end();
			std::advance( it, -i );
		}

		if ( val < *it )
			break;
		i++;
	}

	L.insert( it, i );

	return cmpCount;
}


// Sorters

int	PmergeMe::sortVect( void )
{
	int size = this->_V.size();
	int cmpCount = 0;
	bool hasRmdr = size % 2;

	if ( size < 2 )
	{
		if ( this->_debug ) { std::cout << "[ Vector too small to sort ]\n"; }
		return 0;
	}
	if ( this->_debug ) { std::cout << "[ > Sorting an int vector < ]\n"; }

	int rmdr;
	if ( hasRmdr ) { rmdr = takeLast( this->_V ); }

	PVEC pV;
	while ( !this->_V.empty() )
	{
		PAIR p = makePair( this->_V );
		cmpCount += 1 + insertPair( pV, p );
	}

	for ( PVEC::const_iterator it = pV.begin(); it != pV.end(); it++ ) { this->_V.push_back( it->first ); }
	for ( PVEC::const_iterator it = pV.begin(); it != pV.end(); it++ ) { cmpCount += insertVal( this->_V, it->second ); }

	if ( hasRmdr ) { cmpCount += insertVal( this->_V, rmdr ); }

	if ( this->_debug ) { printPVect( pV, hasRmdr, cmpCount ); }

	return cmpCount;
}


int	PmergeMe::sortList( void )
{
	return 0;
}
