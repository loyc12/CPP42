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

void run( IVEC &V, ILST &L, bool debug )
{


	PmergeMe pV( V, debug );
	PmergeMe pL( L, debug );

	if ( debug )
	{
		std::cout << "\nVector : " << pV;
//		std::cout << "\nList   : " << pL << std::endl;
		std::cout << "\n\nSorting..." << std::endl;
	}
	else
		std::cout << "\nUnsorted : " << pV;

	pV.sort();
//	pL.sort();

	if ( debug )
	{
		std::cout << "\nVector : " << pV;
//		std::cout << "\nList   : " << pL << std::endl;
	}
	else
		std::cout << "\nSorted   : " << pV;

	std::cout << "\nVector of size " << pV.getVect().size() << " sorted in " << pV.getSortTime() << " microseconds";
//	std::cout << "\nList   of size " << pL.getList().size() << " sorted in " << pL.getSortTime() << " microseconds";
	std::cout << "\n" << std::endl;
}

int	main( int ac, char **av )
{
	IVEC V;
	ILST L;

	for ( int i = 1; i < ac; i++ ) { addToContainer( av[i], V, L ); }

	run( V, L, true );
	std::cout << "\n 0============================================================0 " << std::endl;
	run( V, L, false );

}