#include <iostream>

template< typename T > void swap( T &a, T &b )
{
	T tmp = a;
	a = b;
	b = tmp;
}
template< typename T > T const &min( T const &a, T const &b ) { return (a < b ? a : b); }
template< typename T > T const &max( T const &a, T const &b ) { return (a > b ? a : b); }

void runTests( void )
{
	std::cout << "\nO================================ TEST 1 ================================O\n"  << std::endl;
	{
		int a = 2;
		int b = 3;

		swap( a, b );

		std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
	}
	std::cout << "\nO================================ TEST 2 ================================O\n"  << std::endl;
	{
		std::string c = "chaine 1";
		std::string d = "chaine 2";

		swap(c, d);

		std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;
	}
	std::cout << "\nO================================= END ==================================O\n\n" << std::endl;
}


int	main( void )
{
	runTests();
}