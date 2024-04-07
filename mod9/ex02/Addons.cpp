#include "PmergeMe.hpp"


// Vector functions

void	printPVect( PVEC &pV, int hr, int r )
{
	if ( pV.empty() ) { std::cout << "\nEmpty pair vector" << std::endl; return; }
	std::cout << std::endl;

	for ( PVEC::const_iterator it = pV.begin(); it != pV.end(); it++ )
	{ std::cout << "[ " << it->first << " " << it->second << " ]\n"; }

	if ( hr == 1 ) { std::cout << "( " << r << " )\n\n"; }
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

PAIR makePair( IVEC &V )
{
	PAIR p;
	if   ( V.front() >= V.back() ) { p = PAIR( V.front(), V.back() ); }
	else { p = PAIR( V.back(), V.front() ); }
	V.erase( V.begin() );
	V.pop_back();
	return p;
}
/*
bool isSorted( PVEC &pV )
{
	if ( pV.size() < 2 ) { return true;}

	PVIT it = pV.begin();
	while ( it != pV.end() )
	{
		if ( it->first > it->second ) { return false; }
		it++;
	}

	return true;
}

int sortPairVec( PVEC &pV )
{
	int cmpCount = 0;

	PVIT it = pV.begin();
	while ( it != pV.end() )
	{
		cmpCount++;
		if ( it->first > std::next( it )->first )
		{
			std::swap( it->first, std::next( it )->first );
			std::swap( it->second, std::next( it )->second );
		}
		elif ( it->first == std::next( it )->first )
		{
			cmpCount++;
			if ( it->second > std::next( it )->second )
			{
				std::swap( it->second, std::next( it )->second );
				cmpCount++;
			}
		}
		it++;
	}

	if ( isSorted( pV ) )
	{
		cmpCount += pV.size() - 1;
		return cmpCount;
	}
	else { return ( cmpCount + sortPairs( pV )); }
}
*/

int insertPair( PVEC &pV, PAIR p )
{
	//int cmpCount = 0;

	// does a binary search to find the right place to insert the pair, so that the vector stays sorted
	pV.insert( std::upper_bound( pV.begin(), pV.end(), p ), p ); // WARNING : does it work with pairs??

	return 0; // WARNING : doesn't count the comparisons
}

int insertValue( IVEC &V, IVIT max_it, int val )
{
	//int cmpCount = 0;

	// does a binary search to find the right place to insert the value, so that the vector stays sorted
	V.insert( std::upper_bound( V.begin(), max_it, val ), val );

	return 0; // WARNING : doesn't count the comparisons
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

bool isSorted( PLST &pL )
{
	if ( pL.size() < 2 ) { return true;}

	PLIT it = pL.begin();
	while ( it != pL.end() )
	{
		if ( it->first > it->second ) { return false; }
		it++;
	}

	return true;
}

int sortPairs( PLST &pL )
{
	int cmpCount = 0;

	if ( pL.size() < 2 ) { return cmpCount; }

	PLIT it = pL.begin();
	while ( it != pL.end() )
	{
		cmpCount++;
		if ( it->first > it->second ) { std::swap( it->first, it->second ); }
		it++;
	}

	if ( isSorted( pL ) ) { return cmpCount; }
	else { return ( cmpCount + sortPairs( pL )); }
}

