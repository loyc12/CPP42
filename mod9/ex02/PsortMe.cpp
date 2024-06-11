#include "PmergeMe.hpp"

// tl:dr of how ford johnson works :

/*
	0    : INTRO : the Ford-Johnson algorithm ( or merge-insertion sort) is an sorting algorithm that optimizes the number of comparisons by maximizing \
	|              comparisons within ranges of 2n - 1 elements ( aka one less than 2^n ), which are optimal for binary searches, as they required as many \
	|              comparisons as any other ranges between 2^(n-1) and (2^n) - 1 ( inclusively )
	0.1  : NOTE : thus, all insertions and sorts are done via binary searches, which is optimized for ranges of size 2^n - 1, aka one less than a factor of 2
	0.3  : NOTE : it is possible work with duplicates, but it neccesitates significant tweaks to the algorithm ( it should really be a bonus ngl )

	1    : STEP : input an initial, unsorted array of values
	1.2  : STEP : if the lenght of said array is uneven, store one of the numbers away ( we will insert it back at the end )
	1.3  : STEP : pair elements together and store the pairs into a new pair array ( doesn't matter how they get paired )

	2    : STEP : sort the values inside the pairs ( biggest one first is standard )
	2.1  : NOTE : we will call the biggest element of a given pair Pn; Xn, and the smallest; Yn
	2.2  : STEP : sort the pair array based on each pair X's value ( smallest to biggest )
	2.3  : NOTE : this means Pn = [ Xn, Yn ], where Xn > Yn and Xn > X(n-1)
	2.4  : NOTE : this, of course, doesn't not garantee that Yn > Y(n-1), hence the following complex sorting algorithm

	3    : STEP : create a final array and store every Xn in it ( from biggest to smallest )
	3.1  : STEP : put Y0 ( smallest value of P0 ) at the beginning of said final array
	3.2  : EXAMPLE : the array should now look like; [ Y0, X0, X1, X2, X3, X4, X5, ... ]

	==== USING FACTORS OF 2 ====

	4    : STEP : create a variable to store the current range factor ( f ), and initiate it to 2
	4.1  : NOTE : this means that, if the range factor is n, the range size will be n^2
	4.2  : NOTE : I will call each successive range Jn, where n is the range factor

	5    : STEP : iter over each yet-uninserted Yn, where n <= f
	5.1  : IMPORTANT : we need to iterate backwards ( starting from Yf and decresing towards Y0 )
	5.2  : IMPORTANT : we need to avoid inserting the same value twice, and thus need to stop at Y(F-1)
	5.1  : IMPORTANT


	==== USING THE JACKOBSTHAL SEQUENCE ====

	4    : STEP : load or build the jacobsthal sequence ( 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, ... ) ( sequence where Jn = (Jn-1) + 2(Jn-2) )
	4.1  : NOTE : we will call each jacobsthal element Jn. we will use j when a Jn is used as an index ( ex : Xj instead of XJn )
	4.2  : NOTE : we will use these Jn to find each successive insertion range size ( from index 0 to Xj, where j = Jn )
	4.3  : NOTE : the initial Jn value is that of J2 ( value of 3 ), as the insertion of Y0 is trivial and already done ( J0 / J1 are thus skipped )
	4.4  : NOTE : this means the first insertion range is; [ Y0, X0, X1 ]

	5    : STEP : iter over each yet-uninserted Yn, and insert them into the final array
	5.1  : IMPORTANT : you need to insert them in reverse order ( from Yj to Y0, stopping at the previous Yj )
	5.2  : EXAMPLE : inserting Y2 ( largest Yn in range J3 ); [ Y0, X0, X1 ] -> [ Y0, X0, X1, Y2 ]
	5.3  : NOTE : as the iteration range is a fixed size, the final value will be kicked out of the range after each insertion
	5.4  : EXAMPLE : [ Y0, X0, X1, Y2 ] -> [ Y0, X0, X1 ]
	5.5  : NOTE : this is by design, since all remaining insertion in this range are garanteed to be smaller than the kicked value

	6    : STEP : repeat step 5 until all yet uninserted Yn bellow Y(j+1) have been inserted
	6.1  : EXAMPLE : on the first loop ( range of J2 = 3 ), we insert Y2, then Y1. we then finish, as Y0 is already inserted

	7    : STEP : once you are done inserting in this range, set the new range to J(n+1), and go back to step 5 ( again... nested loop are so fun after all )
	7.2  : EXAMPLE : on the second loop ( range of J3 = 5 ), we insert Y4, then Y3, then finish, since Y3 is already inserted
	7.3  : EXAMPLE : on the third loop ( range of J4 = 11 ), we insert Y10 to Y5, then finish, since Y5 is already inserted
	7.4  : NOTE : on each succesive loop, the range increases by a factor of 2, thus making sure it is always optimized for binary search
	7.5  : IMPORTANT : make sure to cap the insertion range to the final array's size ( which is often not equal to 2^n - 1 )

	8    : IMPORTANT : what I call range ( ex : a range of 5 ), is actually the index of the Yn to restart the insertion from
	8.1  : EXAMPLE : this means that range 5 will actually look like [ Y0, X0, X1, Y2, X2, X3, X4 ]
	8.2  : NOTE : the actual "lenght" of each ranges is simply 2n - 1, where n starts a 2 and increase by 1 after each loop

	9   : STEP : once all Yn have been inserted, insert the last remaining Yn ( if any ) into the array via a simple binary search

*/

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
