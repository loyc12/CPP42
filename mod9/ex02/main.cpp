#include "PmergeMe.hpp"

# define PRINT_ALL false

void addToContainer( char *val, IVEC &V, ILST &L )
{
	try
	{
		V.push_back( atoi( val ) );
		L.push_back( atoi( val ) );
	}
	catch ( std::exception &e ) { std::cerr << e.what() << std::endl; }
}

int	main( int ac, char **av )
{
	IVEC V;
	ILST L;

	for ( int i = 1; i < ac; i++ ) { addToContainer( av[i], V, L ); }

	PmergeMe pV( V, PRINT_ALL );
	PmergeMe pL( L, PRINT_ALL );

	std::cout << "\nVector : " << pV;
	std::cout << "\nList   : " << pL << std::endl;

	std::cout << "\nSorting...\n";
	pV.sort(); //						TODO : implement a custom sort
	pL.sort(); //						TODO : implement a custom sort

	std::cout << "\nVector sorted in " << pV.getSortTime() << "ns";
	std::cout << "\nList   sorted in " << pL.getSortTime() << "ns\n";

	std::cout << "\nVector : " << pV;
	std::cout << "\nList   : " << pL << std::endl;

	std::cout << "\nDone !\n";
}