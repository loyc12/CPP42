#include <iostream>
# include "iter.hpp"

void runTests( void )
{
	std::cout << "\n O==================================== TEST 1 ====================================O\n"  << std::endl;
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		iter( arr, 5, print);
	}
	std::cout << "\n O==================================== TEST 2 ====================================O\n"  << std::endl;
	{
		float arr[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
		iter( arr, 5, print);
	}
	std::cout << "\n O===================================== END ======================================O\n\n" << std::endl;
}

int	main( void )
{
	runTests();
}