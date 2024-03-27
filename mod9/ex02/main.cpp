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
		std::cout << "\nList   : " << pL << std::endl;
		std::cout << "\nSorting...\n" << std::endl;
	}
	else
		std::cout << "\nUnsorted : " << pV;

	pV.sort(); //						TODO : implement a custom sort
	pL.sort(); //						TODO : implement a custom sort

	if ( debug )
	{
		std::cout << "\nVector : " << pV;
		std::cout << "\nList   : " << pL << std::endl;
	}
	else
		std::cout << "\nSorted   : " << pV;

	std::cout << "\nVector of size " << pV.getVect().size() << " sorted in " << pV.getSortTime() << "ns";
	std::cout << "\nList   of size " << pL.getList().size() << " sorted in " << pL.getSortTime() << "ns\n\n";
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