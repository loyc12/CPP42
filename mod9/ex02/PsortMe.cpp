#include "PmergeMe.hpp"

#define PVEC std::vector< std::pair< int, int > >
#define PLST std::list< std::pair< int, int > >

// Jacobstal sequence ( fomr index 1 of OEIS A001045 )
#define JNUM { 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, \
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
}

void	printPList( PLST &pL, bool hr, int r )
{
	if ( pL.empty() ) { std::cout << "\nEmpty pair list" << std::endl; return; }
	std::cout << std::endl;

	for ( PLST::const_iterator it = pL.begin(); it != pL.end(); it++ )
	{ std::cout << "[ " << it->first << " " << it->second << " ]\n"; }

	if ( hr ) { std::cout << "( " << r << " )\n\n"; }
}



// Sorters

void	PmergeMe::sortVect( void )
{
	if ( this->_V.size() < 2 )
	{
		if ( this->_debug ) { std::cout << "[ Vector too small to sort ]\n"; }
		return;
	}
	if ( this->_debug ) { std::cout << "[ > Sorting an int vector < ]\n"; }

	bool hasRemainder = this->_V.size() % 2;
	int remainder = 0;
	if ( hasRemainder ) { remainder = this->_V.back(); }

	if ( this->_debug ) { std::cout << "[ Creating an int pair vector from the in vector]\n"; }
	PVEC pV;

	// puts values from the vectors into a vector of pairs of values, two at a time, leaving the last one alone if uneven
	for ( size_t i = 0; i < this->_V.size(); i += 2 )
		if ( i + 1 < this->_V.size() ) { pV.push_back( std::make_pair( this->_V[ i ], this->_V[ i + 1 ] )); }

	//printPVect( pV, hasRemainder, remainder );

	if ( this->_debug ) { std::cout << "[ Sorting the int pair vector ]\n"; }

	// sorts the pairs of values, smallest first, biggest last
	for ( PVEC::iterator it = pV.begin(); it != pV.end(); it++ )
		if ( it->first > it->second ) { std::swap( it->first, it->second ); }

	// sorts the pair vector based on the first value of each pair
	for ( PVEC::iterator it = pV.begin(); it != pV.end(); it++ )
	{
		PVEC::iterator it2 = it;

		while ( it2 != pV.begin() && ( it2 - 1 )->first >= it2->first )
		{
			// sorts the pair vector based on the second value if the first is the same
			if (( it2 - 1 )->first == it2->first && ( it2 - 1 )->second <= it2->second ) { break; }
			std::iter_swap( it2, it2 - 1 );
			it2--;
		}
	}

	printPVect( pV, hasRemainder, remainder );

	if ( this->_debug ) { std::cout << "[ reseting the int vector ]\n"; }
	this->_V.clear();

	// reinserts the first value of each pair into a new vector
	if ( this->_debug ) { std::cout << "[ Reinserting the first value of each pair ]\n"; }

	for ( PVEC::iterator it = pV.begin(); it != pV.end(); it++ ) { this->_V.push_back( it->first ); }

	//std::cout << std::endl;  this->writeVect( std::cout );  std::cout << std::endl;

	// reinserts the second value of each pair into the vector
	if ( this->_debug ) { std::cout << "[ Reinserting the second value of each pair ]\n"; }

	//int jnum[] = JNUM;
	for ( PVEC::iterator it = std::prev( pV.end() ); it != pV.begin(); it-- )
	{
		int val = it->second;
		// use the jacobsthal sequence to insert the last number from the pairs (in reverse order) into the sequence
		for ( IVEC::iterator it2 = --this->_V.end(); it2 != this->_V.begin(); it2--, i++ )
			if ( it->second >= *it2 ) { this->_V.insert( std::next( it2 ), val );  break; }
	}
/*
	int index = 0;
	for ( PVEC::iterator it = pV.begin(); it != pV.end(); it++, index++ )
	{
		int val = it->second;
		IVEC::iterator it2 = this->_V.begin();
		for ( std::advance( it2, index ); it2 != this->_V.end(); it2++ )
		{
			if   ( it->second <= *it2 ) { this->_V.insert( it2, val );  break; }
			elif ( std::next( it2 ) == this->_V.end() ) { this->_V.push_back( val );  break; }
		}
	}
*/

	// reinserts the remainder if there is one
	if ( hasRemainder )
	{
		//std::cout << std::endl;  this->writeVect( std::cout );  std::cout << std::endl;

		if ( this->_debug ) { std::cout << "[ Reinserting the remaining value ]\n"; }

		for ( IVEC::iterator it = this->_V.begin(); it != this->_V.end(); it++ )
		{
			if   ( remainder <= *it ) { this->_V.insert( it, remainder );  break; }
			elif ( std::next( it ) == this->_V.end() ) { this->_V.push_back( remainder );  break; }
		}
	}

	//std::cout << std::endl;  this->writeVect( std::cout );  std::cout << std::endl;
}





void	PmergeMe::sortList( void )
{
	if ( this->_L.size() < 2 )
	{
		if ( this->_debug ) { std::cout << "[ List too small to sort ]\n"; }
		return;
	}
	if ( this->_debug ) { std::cout << "[ > Sorting an int list < ]\n"; }

	bool hasRemainder = this->_L.size() % 2;
	int remainder = 0;
	if ( hasRemainder ) { remainder = this->_L.back(); this->_L.pop_back(); }

	if ( this->_debug ) { std::cout << "[ Creating an int pair list ]\n"; }
	PLST pL;

	// puts values from the list into a list of pairs of values, two at a time, leaving the last one alone if uneven
	for ( ILST::iterator it = this->_L.begin(); it != this->_L.end(); it++ )
		if ( std::next( it ) != this->_L.end() ) { pL.push_back( std::make_pair( *it, *std::next( it++ ))); }

	//printPList( pL, hasRemainder, remainder );

	if ( this->_debug ) { std::cout << "[ Sorting the int pair list ]\n"; }

	// sorts the pairs of values, smallest first, biggest last
	for ( PLST::iterator it = pL.begin(); it != pL.end(); it++ )
		if ( it->first > it->second ) { std::swap( it->first, it->second ); }

	// sorts the pair list based on the first value of each pair
	for ( PLST::iterator it = pL.begin(); it != pL.end(); it++ )
	{
		PLST::iterator it2 = it;
		while ( it2 != pL.begin() && ( std::prev( it2 )->first >= it2->first ))
		{
			// sorts the pair list based on the second value if the first is the same
			if (( std::prev( it2 ))->first == it2->first && ( std::prev( it2 ))->second <= it2->second ) { break; }
			std::iter_swap( it2, std::prev( it2 ));
			it2--;
		}
	}

	//printPList( pL, hasRemainder, remainder );

	if ( this->_debug ) { std::cout << "\n[ Reseting the int list ]"; }
	this->_L.clear();

	// reinserts the first value of each pair into a new list
	if ( this->_debug ) { std::cout << "\n[ Reinserting the first value of each pair ]"; }

	for ( PLST::iterator it = pL.begin(); it != pL.end(); it++ ) { this->_L.push_back( it->first ); }

	//std::cout << std::endl;  this->writeList( std::cout );  std::cout << std::endl;

	// reinserts the second value of each pair into the list
	if ( this->_debug ) { std::cout << "\n[ Reinserting the second value of each pair ]"; }

	int index = 0;
	for ( PLST::iterator it = pL.begin(); it != pL.end(); it++, index++ )
	{
		int val = it->second;
		ILST::iterator it2 = this->_L.begin();
		for ( std::advance( it2, index ); it2 != this->_L.end(); it2++ )
		{
			if   ( it->second <= *it2 ) { this->_L.insert( it2, val );  break; }
			elif ( std::next( it2 ) == this->_L.end() ) { this->_L.push_back( val );  break; }
		}
	}

	// reinserts the remainder if there is one
	if ( hasRemainder )
	{
		//std::cout << std::endl;  this->writeList( std::cout );  std::cout << std::endl;

		if ( this->_debug ) { std::cout << "\n[ Reinserting the remaining value ]"; }

		for ( ILST::iterator it = this->_L.begin(); it != this->_L.end(); it++ )
		{
			if   ( remainder <= *it ) { this->_L.insert( it, remainder );  break; }
			elif ( it == --( this->_L.end() )) { this->_L.push_back( remainder );  break; }
		}
	}

	//std::cout << std::endl;  this->writeList( std::cout );  std::cout << std::endl;
}
