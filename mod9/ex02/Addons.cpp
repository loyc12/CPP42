#include "PmergeMe.hpp"
#include <math.h>


// Vector functions

void	printPVect( PVEC &pV, int hr, int r )
{
	std::cout << std::endl;
	if ( pV.empty() ) { std::cout << "Empty pair vector\n" << std::endl; return; }

	for ( PVEC::const_iterator it = pV.begin(); it != pV.end(); it++ )
	{ std::cout << "[ " << it->first << " " << it->second << " ]\n"; }

	if ( hr == 1 ) { std::cout << "( " << r << " )\n"; }
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

PAIR makePair( IVEC &V )
{
	PAIR p;
	if   ( V.front() >= V.back() ) { p = PAIR( V.front(), V.back() ); }
	else { p = PAIR( V.back(), V.front() ); }
	V.erase( V.begin() );
	V.pop_back();
	return p;
}

//int insertPair( PVEC &pV, PAIR p ) { return insertPair( pV, p, false ); }
int insertPair( PVEC &pV, PAIR p, bool debug )
{
	int maxCmp = 0;

	if ( debug ) // WARNING : assumes worst case comparisons
	{
		maxCmp = ( int )log2( pV.size() + 1);
		if ( maxCmp < 0 ) { maxCmp = 0; }
	}

	// does a binary search to find the right place to insert the pair
	pV.insert( std::upper_bound( pV.begin(), pV.end(), p ), p );

	return maxCmp;
}

//int insertValue( IVEC &V, IVIT max_it, int val ) { return insertValue( V, max_it, val, false ); }
int insertValue( IVEC &V, IVIT max_it, int val, bool debug )
{
	int maxCmp = 0;
	if ( debug ) // WARNING : assumes worst case comparisons
	{
		maxCmp = ( int )log2( std::distance( V.begin(), max_it ) + 1 );
		if ( maxCmp < 0 ) { maxCmp = 0; }
	}

	// does a binary search to find the right place to insert the value
	V.insert( std::upper_bound( V.begin(), max_it, val ), val );

	return maxCmp;
}



// List functions

void	printPList( PLST &pL, int hr, int r )
{
	if ( pL.empty() ) { std::cout << "\nEmpty pair list" << std::endl; return; }
	std::cout << std::endl;

	for ( PLST::const_iterator it = pL.begin(); it != pL.end(); it++ )
	{ std::cout << "[ " << it->first << " " << it->second << " ]\n"; }

	if ( hr == 1 ) { std::cout << "( " << r << " )\n\n"; }
	std::cout << std::endl;
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

PAIR makePair( ILST &L )
{
	PAIR p;
	if   ( L.front() >= L.back() ) { p = PAIR( L.front(), L.back() ); }
	else { p = PAIR( L.back(), L.front() ); }
	L.pop_front();
	L.pop_back();
	return p;
}

//int insertPair( PLST &pL, PAIR p ) { return insertPair( pL, p, false ); }
int insertPair( PLST &pL, PAIR p, bool debug )
{
	int maxCmp = 0;

	if ( debug ) // WARNING : assumes worst case comparisons
	{
		maxCmp = ( int )log2( pL.size() + 1);
		if ( maxCmp < 0 ) { maxCmp = 0; }
	}

	// does a binary search to find the right place to insert the pair
	pL.insert( std::upper_bound( pL.begin(), pL.end(), p ), p );

	return maxCmp;
}

//int insertValue( ILST &L, ILIT max_it, int val ) { return insertValue( L, max_it, val, false ); }
int insertValue( ILST &L, ILIT max_it, int val, bool debug )
{
	int maxCmp = 0;
	if ( debug ) // WARNING : assumes worst case comparisons
	{
		maxCmp = ( int )log2( std::distance( L.begin(), max_it ) + 1 );
		if ( maxCmp < 0 ) { maxCmp = 0; }
	}

	// does a binary search to find the right place to insert the value
	L.insert( std::upper_bound( L.begin(), max_it, val ), val );

	return maxCmp;
}