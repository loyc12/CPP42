#include "PmergeMe.hpp"

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
			//printPVect( pV, hasRmdr, rmdr );
		}
	}

	// inserting the main chain on _V
	this->_V.push_back( pV.front().second ); // inserts the first element of the pend chain
	for ( PVIT it = pV.begin(); it != pV.end(); it++ ) { this->_V.push_back( it->first ); }

	// initiating vars for the Ford-Johnson algorithm
	int JD[] = JDIF; //	jacobsthal sequence (from 3 onward)
	int j = 0;
	int step = 0; //					range increase lenght
	int tmp;

	IVIT v_it = this->_V.begin(); //	main chain iterator
	PVIT p_it = pV.begin(); //			pend chain iterator
	PVIT p_stop = pV.begin(); //		pend chain range stop  ( exclusive )
	PVIT p_start = pV.begin(); //		pend chain range start ( inclusive )

	// inserting the pend chain's elements (except the first) back on _V using the jacobsthal sequence
	while ( true )
	{
		if ( p_stop == std::prev( pV.end() )) { break; }
		step = JD[ j++ ];
		if_DBG { std::cout << "\nBase step lenght : " << step; }

		// incrementing the extract range and making sure it's valid
		tmp = ( int )std::distance( p_start, pV.end() );
		if ( tmp <= step ) { step = tmp - 1; }

		std::advance( p_start, step );
		if_DBG { std::cout << "\nExtract range : " << std::distance( pV.begin(), p_start ) << " to " << 1 + std::distance( pV.begin(), p_stop ) << std::endl; }
		p_it = p_start;

		// incrementing the insert range and making sure it's valid
		tmp = ( int )std::distance( v_it, this->_V.end() );
		if ( tmp <= step * 2 ) { step = tmp / 2; }

		std::advance( v_it, step * 2 );
		if_DBG { std::cout << "Insert range : 0 to " << std::distance( this->_V.begin(), v_it ) << std::endl << std::endl; }

		// looping through the extract range and inserting the the pairs' smallest value into the insert range
		while ( p_it != p_stop )
		{
			maxCmp += insertValue( this->_V, v_it, p_it->second, this->_debug );
			if_DBG { std::cout << "Inserting [ " << std::distance( pV.begin(), p_it ) << " ] == " << p_it->second << std::endl; }
			p_it--;
		}

		// marking range as done
		p_stop = p_start;
	}

	// inserting the last element of the pend chain
	if ( hasRmdr == 1 ) { maxCmp += insertValue( this->_V, std::prev( this->_V.end() ), rmdr, this->_debug ); }

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
			//printPList( pL, hasRmdr, rmdr );
		}
	}

	// inserting the main chain on _L
	this->_L.push_back( pL.front().second ); // inserts the first element of the pend chain
	for ( PLIT it = pL.begin(); it != pL.end(); it++ ) { this->_L.push_back( it->first ); }

	// initiating vars for the Ford-Johnson algorithm
	int JD[] = JDIF; //	jacobsthal sequence (from 3 onward)
	int j = 0;
	int step = 0; //					range increase lenght
	int tmp;

	ILIT l_it = this->_L.begin(); //	main chain iterator
	PLIT p_it = pL.begin(); //			pend chain iterator
	PLIT p_stop = pL.begin(); //		pend chain range stop  ( exclusive )
	PLIT p_start = pL.begin(); //		pend chain range start ( inclusive )

	// inserting the pend chain's elements (except the first) back on _L using the jacobsthal sequence
	while ( true )
	{
		if ( p_stop == std::prev( pL.end() )) { break; }
		step = JD[ j++ ];
		if_DBG { std::cout << "\nBase step lenght : " << step; }

		// incrementing the extract range and making sure it's valid
		tmp = ( int )std::distance( p_start, pL.end() );
		if ( tmp <= step ) { step = tmp - 1; }

		std::advance( p_start, step );
		if_DBG { std::cout << "\nExtract range    : " << std::distance( pL.begin(), p_start ) << " to " << 1 + std::distance( pL.begin(), p_stop ) << std::endl; }
		p_it = p_start;

		// incrementing the insert range and making sure it's valid
		tmp = ( int )std::distance( l_it, this->_L.end() );
		if ( tmp <= step * 2 ) { step = tmp / 2; }

		std::advance( l_it, step * 2 );
		if_DBG { std::cout << "Insert range     : 0 to " << std::distance( this->_L.begin(), l_it ) << std::endl << std::endl; }


		// looping through the extract range and inserting the the pairs' smallest value into the insert range
		while ( p_it != p_stop )
		{
			maxCmp += insertValue( this->_L, l_it, p_it->second, this->_debug );
			if_DBG { std::cout << "Inserting [ " << std::distance( pL.begin(), p_it ) << " ] == " << p_it->second << std::endl; }
			p_it--;
		}

		// marking range as done
		p_stop = p_start;
	}

	// inserting the last element of the pend chain
	if ( hasRmdr == 1 ) { maxCmp += insertValue( this->_L, std::prev( this->_L.end() ), rmdr, this->_debug ); }

	return maxCmp; // WARNING : supposed to assume the worst case scenario, but innacurate af
}
