#include "PmergeMe.hpp"

// Sorters

// sorts a vector of ints using the Ford-Johnson algorithm
int	PmergeMe::sortVect( void )
{
	int size = ( int )this->_V.size();
	int cmpCount = 0;
	int hasRmdr = size % 2;

	// checking if the size if valid
	if ( size < 2 )
	{
		if ( this->_debug ) { std::cout << "[ Vector too small to sort ]\n"; }
		return 0;
	}
	if ( this->_debug ) { std::cout << "[ Sorting an int vector ]\n"; }

	// storing an element away if the qqt is odd
	int rmdr;
	if ( hasRmdr == 1 ) { rmdr = takeLast( this->_V ); }

	// creating a sorted [ a(i), b(i) ] pair vector where ( a(i) <= b(i) & a(i) <= a(i+1) )
	PVEC pV;
	while ( !this->_V.empty() )
	{
		cmpCount += insertPair( pV, makePair( this->_V ) );
		cmpCount++; // for makePair's comparison
	}

	printPVect( pV, hasRmdr, rmdr );

	// inserting the main chain on _V
	this->_V.push_back( pV.front().second ); // inserts the first element of the pend chain
	for ( PVIT it = pV.begin(); it != pV.end(); it++ ) { this->_V.push_back( it->first ); }

	// initiating vars for the Ford-Johnson algorithm
	int J[] = JNUM; //	jacobsthal sequence (from 3 onward)

	int j = 0; //			current jacobsthal index
	int i = 1; //			current pit index
	int lastMax = 1 ; //	current maximum pit index
	int nextMax = 1; //		next maximum pit index

	IVIT v_it = this->_V.begin(); //	current vect it
	PVIT p_it = pV.begin(); //			current pair it

	// inserting the pend chain's elements (except the first) back on _V using the jacobsthal sequence
	size = size - hasRmdr;

	while ( true )
	{
		if ( i <= lastMax )
		{
			lastMax = nextMax;
			nextMax = J[ j++ ];

			i = nextMax;
			if ( i >= size ) { i = size; }
		}
		if ( lastMax >= size ) { break; }

		// inserting the next element of the pend chain
		if ( nextMax >= ( int )this->_V.size() )
		{
			v_it = this->_V.end();
			std::cout << "putting v_it at end" << std::endl;
		}
		else
		{
			v_it = this->_V.begin();
			std::advance( v_it, nextMax );
			std::cout << "putting v_it at " << nextMax << std::endl;
		}

		p_it = pV.begin();
		std::advance( p_it, i );
		std::cout << "putting p_it at " << i << std::endl;

		cmpCount += insertValue( this->_V, v_it, p_it->second );
		std::cout << "inserting " << p_it->second << " between start and " << nextMax << std::endl;

		i--;
	}

	// inserting the last element of the pend chain
	if ( hasRmdr == 1 ) { cmpCount += insertValue( this->_V, this->_V.end(), rmdr ); }

	return cmpCount;
}


int	PmergeMe::sortList( void )
{
	return 0;
}
