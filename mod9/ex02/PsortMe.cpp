#include "PmergeMe.hpp"

#define PVEC std::vector< std::pair< int, int > >
#define PLST std::list< std::pair< int, int > >


// TODO : use jacobstal to reinsert the last number from pair into the "array" of numbers (in order)


// Debug printers

void	printPVect( PVEC &pV, bool hr, int r )
{
	if ( pV.empty() ) { std::cout << "\nEmpty pair vector" << std::endl; return; }
	std::cout << std::endl;

	for ( PVEC::const_iterator it = pV.begin(); it != pV.end(); it++ )
	{
		std::cout << "[ " << it->first << " " << it->second << " ]";
		if ( it != --( pV.end() )) { std::cout << " "; }
	}

	if ( hr ) { std::cout << " ( " << r << " )"; }
	std::cout << std::endl;
}

void	printPList( PLST &pL, bool hr, int r )
{
	if ( pL.empty() ) { std::cout << "\nEmpty pair list" << std::endl; return; }
	std::cout << std::endl;

	for ( PLST::const_iterator it = pL.begin(); it != pL.end(); it++ )
	{
		std::cout << "[ " << it->first << " " << it->second << " ]";
		if ( it != --( pL.end() )) { std::cout << " "; }
	}

	if ( hr ) { std::cout << " ( " << r << " )"; }
	std::cout << std::endl;
}



// Sorters

void	PmergeMe::sortVect( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a vector ]\n"; }

	PVEC pV;
	PVEC::iterator it;
	bool hasReminder = false;
	int reminder = 0;

	if ( this->_debug ) { std::cout << "[ Creating a pair vector ]\n"; }

	// puts values from the vectors into a vector of pairs of values, two at a time, leaving the last one alone if uneven
	for ( size_t i = 0; i < this->_V.size(); i += 2 )
	{
		if ( i + 1 < this->_V.size() )
			pV.push_back( std::make_pair( this->_V[ i ], this->_V[ i + 1 ] ) );
		else
		{
			hasReminder = true;
			reminder = this->_V[ i ];
		}
	}

	//printPVect( pV, hasReminder, reminder );

	// sorts the pairs of values, smallest first, biggest last
	if ( this->_debug ) { std::cout << "\n[ Sorting the pairs ]"; }

	for ( it = pV.begin(); it != pV.end(); it++ )
	{
		if ( it->first > it->second )
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}

	//printPVect( pV, hasReminder, reminder );

	// sorts the pair vector based on the first value of each pair
	if ( this->_debug ) { std::cout << "\n[ Sorting the pair vector based on the pairs' first value ]"; }

	for ( it = pV.begin(); it != pV.end(); it++ )
	{
		PVEC::iterator it2 = it;
		// sorts the pair vector based on the first value of each pair, or the second value if the first is the same
		while ( it2 != pV.begin() && ( it2 - 1 )->first >= it2->first )
		{
			if (( it2 - 1 )->first == it2->first && ( it2 - 1 )->second <= it2->second ) { break; }
			std::iter_swap( it2, it2 - 1 );
			it2--;
		}
	}

	//printPVect( pV, hasReminder, reminder );

	// reinserts the first value of each pair into a new vector
	if ( this->_debug ) { std::cout << "\n[ Reinserting the first value of each pair into a new vector ]"; }

	this->_V.clear();
	for ( it = pV.begin(); it != pV.end(); it++ ) { this->_V.push_back( it->first ); }

	//std::cout << std::endl;  this->writeVect( std::cout );  std::cout << std::endl;

	// reinserts each second value of each pair into the vector
	if ( this->_debug ) { std::cout << "\n[ Reinserting the second value of each pair into the vector using jacobstal ]"; }

	for ( it = pV.begin(); it != pV.end(); it++ )
	{
		int val = it->second;
		for ( IVEC::iterator it2 = this->_V.begin(); it2 != this->_V.end(); it2++ )
		{
			if   ( val <= *it2 ) { this->_V.insert( it2, val );  break; }
			elif ( it2 == --( this->_V.end() )) { this->_V.push_back( val );  break; }
		}
	}


	// reinserts the reminder if there is one
	if ( hasReminder )
	{
		//std::cout << std::endl;  this->writeVect( std::cout );  std::cout << std::endl;

		if ( this->_debug ) { std::cout << "\n[ Reinserting the reminder into the vector ]"; }

		for ( IVEC::iterator it2 = this->_V.begin(); it2 != this->_V.end(); it2++ )
		{
			if   ( reminder <= *it2 ) { this->_V.insert( it2, reminder );  break; }
			elif ( it2 == --( this->_V.end() )) { this->_V.push_back( reminder );  break; }
		}
	}

	//std::cout << std::endl;  this->writeVect( std::cout );  std::cout << std::endl;
}





void	PmergeMe::sortList( void )
{
	if ( this->_debug ) { std::cout << "[ Sorting a list ]\n"; }

	PLST pL;
	PLST::iterator it;
	bool hasReminder = false;
	int reminder = 0;

	if ( this->_debug ) { std::cout << "[ Creating a pair list ]\n"; }

	// puts values from the list into a list of pairs of values, two at a time, leaving the last one alone if uneven
	for ( ILST::iterator it2 = this->_L.begin(); it2 != this->_L.end(); it2++ )
	{
		if ( std::next( it2 ) != this->_L.end() )
		{
			pL.push_back( std::make_pair( *it2, *std::next( it2 )));
			it2++;
		}
		else
		{
			hasReminder = true;
			reminder = *it2;
		}
	}

	//printPList( pL, hasReminder, reminder );

	// sorts the pairs of values, smallest first, biggest last
	if ( this->_debug ) { std::cout << "\n[ Sorting the pairs ]"; }

	for ( it = pL.begin(); it != pL.end(); it++ )
	{
		if ( it->first > it->second )
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}

	//printPList( pL, hasReminder, reminder );

	// sorts the pair list based on the first value of each pair
	if ( this->_debug ) { std::cout << "\n[ Sorting the pair list based on the pairs' first value ]"; }

	for ( it = pL.begin(); it != pL.end(); it++ )
	{
		PLST::iterator it2 = it;
		// sorts the pair list based on the first value of each pair, or the second value if the first is the same
		while ( it2 != pL.begin() && ( std::prev( it2 )->first >= it2->first ))
		{
			if (( std::prev( it2 ))->first == it2->first && ( std::prev( it2 ))->second <= it2->second ) { break; }
			std::iter_swap( it2, std::prev( it2 ));
			it2--;
		}
	}

	//printPList( pL, hasReminder, reminder );

	// reinserts the first value of each pair into a new list
	if ( this->_debug ) { std::cout << "\n[ Reinserting the first value of each pair into a new list ]"; }

	this->_L.clear();
	for ( it = pL.begin(); it != pL.end(); it++ ) { this->_L.push_back( it->first ); }

	//std::cout << std::endl;  this->writeList( std::cout );  std::cout << std::endl;

	// reinserts each second value of each pair into the list
	if ( this->_debug ) { std::cout << "\n[ Reinserting the second value of each pair into the list using jacobstal ]"; }

	for ( it = pL.begin(); it != pL.end(); it++ )
	{
		int val = it->second;
		for ( ILST::iterator it2 = this->_L.begin(); it2 != this->_L.end(); it2++ )
		{
			if   ( val <= *it2 ) { this->_L.insert( it2, val );  break; }
			elif ( it2 == --( this->_L.end() )) { this->_L.push_back( val );  break; }
		}
	}

	// reinserts the reminder if there is one
	if ( hasReminder )
	{
		//std::cout << std::endl;  this->writeList( std::cout );  std::cout << std::endl;

		if ( this->_debug ) { std::cout << "\n[ Reinserting the reminder into the list ]"; }

		for ( ILST::iterator it2 = this->_L.begin(); it2 != this->_L.end(); it2++ )
		{
			if   ( reminder <= *it2 ) { this->_L.insert( it2, reminder );  break; }
			elif ( it2 == --( this->_L.end() )) { this->_L.push_back( reminder );  break; }
		}
	}

	//std::cout << std::endl;  this->writeList( std::cout );  std::cout << std::endl;
}
