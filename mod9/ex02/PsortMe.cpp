#include "PmergeMe.hpp"

// Sorters

// sorts a vector of ints using the Ford-Johnson algorithm
int	PmergeMe::sortVect( void )
{
	int size = ( int )this->_V.size();
	int maxCmp = 0;
	int hasRmdr = size % 2;

	// checking if the size if valid
	if ( size < 2 )
	{
		if_DBG { std::cout << "... not! Vector too small\n"; }
		return 0;
	}
	if_DBG { std::cout << "an int vector\n"; }

	// storing an element away if the qqt is odd
	int rmdr;
	if ( hasRmdr == 1 ) { rmdr = takeLast( this->_V ); }

	// creating a sorted [ a(i), b(i) ] pair vector where ( a(i) <= b(i) & a(i) <= a(i+1) )
	PVEC pV;
	while ( !this->_V.empty() )
	{
		maxCmp += insertPair( pV, makePair( this->_V ), this->_debug );
		if_DBG
		{
			maxCmp++; // adds the makePair() comparison
			printPVect( pV, hasRmdr, rmdr );
		}
	}

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
	size = ( size - hasRmdr ) / 2;

	while ( true )
	{
		// if needed, getting the next insert range via jacobsthal sequence
		if ( i <= lastMax )
		{
			lastMax = nextMax;
			nextMax = J[ j++ ];
			i = nextMax;

			if ( lastMax >= size ) { break; }
			if ( i >= size ) { i = size; }
			if_DBG { std::cout << "\nsearch size : " << nextMax << std::endl; }
		}

		// making sure the insert range is valid
		v_it = this->_V.begin();
		if   ( nextMax * 2 > ( int )this->_V.size() ) { std::advance( v_it, ( int )this->_V.size() ); }
		else { std::advance( l_it, nextMax * 2 ); } // NOTE : not sure *2 should be there...

		// inserting the next element of the pend chain into the range
		p_it = pV.begin();
		std::advance( p_it, i - 1 );

		if_DBG { std::cout << "inserting [ " << i << " ] == " << p_it->second << std::endl; }
		maxCmp += insertValue( this->_V, v_it, p_it->second, this->_debug );

		i--;
	}

	// inserting the last element of the pend chain
	if ( hasRmdr == 1 ) { maxCmp += insertValue( this->_V, this->_V.end(), rmdr, this->_debug ); }

	return maxCmp; // WARNING : supposed to assume the worst case scenario, but innacurate af
}




// sorts a list of ints using the Ford-Johnson algorithm
int	PmergeMe::sortList( void )
{
	int size = ( int )this->_L.size();
	int maxCmp = 0;
	int hasRmdr = size % 2;

	// checking if the size if valid
	if ( size < 2 )
	{
		if_DBG { std::cout << "... not! List too small\n"; }
		return 0;
	}
	if_DBG { std::cout << "an int list\n"; }

	// storing an element away if the qqt is odd
	int rmdr;
	if ( hasRmdr == 1 ) { rmdr = takeLast( this->_L ); }

	// creating a sorted [ a(i), b(i) ] pair list where ( a(i) <= b(i) & a(i) <= a(i+1) )
	PLST pL;
	while ( !this->_L.empty() )
	{
		maxCmp += insertPair( pL, makePair( this->_L ), this->_debug );
		if_DBG
		{
			maxCmp++; // adds the makePair() comparison
			printPList( pL, hasRmdr, rmdr );
		}
	}

	// inserting the main chain on _L
	this->_L.push_back( pL.front().second ); // inserts the first element of the pend chain
	for ( PLIT it = pL.begin(); it != pL.end(); it++ ) { this->_L.push_back( it->first ); }

	// initiating vars for the Ford-Johnson algorithm
	int J[] = JNUM; //	jacobsthal sequence (from 3 onward)

	int j = 0; //			current jacobsthal index
	int i = 1; //			current pit index
	int lastMax = 1 ; //	current maximum pit index
	int nextMax = 1; //		next maximum pit index

	ILIT l_it = this->_L.begin(); //	current list it
	PLIT p_it = pL.begin(); //			current pair it

	// inserting the pend chain's elements (except the first) back on _L using the jacobsthal sequence
	size = ( size - hasRmdr ) / 2;

	while ( true )
	{
		// if needed, getting the next insert range via jacobsthal sequence
		if ( i <= lastMax )
		{
			lastMax = nextMax;
			nextMax = J[ j++ ];
			i = nextMax;

			if ( lastMax >= size ) { break; }
			if ( i >= size ) { i = size; }
			if_DBG { std::cout << "\nsearch size : " << nextMax << std::endl; }
		}

		// making sure the insert range is valid
		l_it = this->_L.begin();
		if   ( nextMax * 2 > ( int )this->_L.size() ) { std::advance( l_it, ( int )this->_L.size() ); }
		else { std::advance( l_it, nextMax * 2 ); } // NOTE : not sure *2 should be there...

		// inserting the next element of the pend chain into the range
		p_it = pL.begin();
		std::advance( p_it, i - 1 );

		if_DBG { std::cout << "inserting [ " << i << " ] == " << p_it->second << std::endl; }
		maxCmp += insertValue( this->_L, l_it, p_it->second, this->_debug );

		i--;
	}

	// inserting the last element of the pend chain
	if ( hasRmdr == 1 ) { maxCmp += insertValue( this->_L, this->_L.end(), rmdr, this->_debug ); }

	return maxCmp; // WARNING : supposed to assume the worst case scenario, but innacurate af
}
