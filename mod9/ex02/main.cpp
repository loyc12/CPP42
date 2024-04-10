#include "PmergeMe.hpp"

void addToContainer( char *val, IVEC &V, ILST &L )
{
	try
	{
		V.push_back( atoi( val ) );
		L.push_back( atoi( val ) );
	}
	catch ( std::exception &e ) { std::cerr << e.what() << std::endl; }
}

void iterOver( int end )
{
	int J[] = JDIF;
	int i = 0;
	int step = 0;

	int i_max = 0;
	int r_pos = 0;
	int r_start = 0;
	int r_stop = 0;

	while ( true )
	{
		if ( r_stop == end ) { break; }
		step = J[ i++ ];

		r_start += step;
		if ( r_start >= end ) { r_start = end; }
		r_pos = r_start;

		i_max += step * 2;
		if ( i_max >= end * 2 ) { i_max = end * 2; }

		std::cout << "Range : " << r_start << " to " << r_stop << std::endl;
		std::cout << "Max   : " << i_max << "\nInserts: ";
		while ( r_pos > r_stop )
		{
			std::cout << r_pos << ", ";
			r_pos--;
		}
		std::cout << std::endl << std::endl;

		r_stop = r_start;
	}

}

void run( IVEC &V, ILST &L, bool debug )
{
	PmergeMe pV( V, debug );
	PmergeMe pL( L, debug );

	if ( debug )
	{
		//iterOver( V.size() / 2 );

		std::cout << "\nVector : " << pV;
		std::cout << "\nList   : " << pL;
		std::cout << std::endl;
	}
	else
		std::cout << "\nUnsorted : " << pV;

	pV.sort();
	pL.sort();

	if ( debug )
	{
		std::cout << "\nVector : " << pV;
		std::cout << "\nList   : " << pL;
	}
	else
		std::cout << "\nSorted   : " << pV;

	std::cout << std::endl;
	std::cout << "\nVector of size " << pV.getVect().size() << " sorted in " << pV.getSortTime() << " microseconds";
	std::cout << "\nList   of size " << pL.getList().size() << " sorted in " << pL.getSortTime() << " microseconds";
	std::cout << std::endl;
}

int	main( int ac, char **av )
{
	IVEC V;
	ILST L;

	for ( int i = 1; i < ac; i++ ) { addToContainer( av[i], V, L ); }

	//run( V, L, true );

	std::cout << "\n 0=================================================================================================0 " << std::endl;
	run( V, L, false );
	std::cout << "\n 0=================================================================================================0 " << std::endl;
}