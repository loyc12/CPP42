#include <iostream>
#include "template.hpp"

void runTests( void )
{
	std::cout << "\n O==================================== TEST 1 ====================================O\n"  << std::endl;
	{
		int a = 2;
		int b = 3;

		std::cout << "  a = " << a << ", b = " << b << std::endl << std::endl;
		std::cout << "  swaping a & b" << std::endl << std::endl;
		swap( a, b );

		std::cout << "  a = " << a << ", b = " << b << std::endl << std::endl;
		std::cout << "  min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "  max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	std::cout << "\n O==================================== TEST 2 ====================================O\n"  << std::endl;
	{
		std::string c = "chaine 1";
		std::string d = "chaine 2";

		std::cout << "  c = " << c << ", d = " << d << std::endl << std::endl;
		std::cout << "  swaping c & d" << std::endl << std::endl;
		swap( c, d );

		std::cout << "  c = " << c << ", d = " << d << std::endl << std::endl;
		std::cout << "  min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "  max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << "\n O===================================== END ======================================O\n\n" << std::endl;
}


int	main( void )
{
	runTests();
}