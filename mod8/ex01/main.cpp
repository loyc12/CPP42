#include <iostream>
#include "Span.hpp"

void test( int length )
{
	try
	{
		Span t1( length );

		for ( int i = 0; i < length; i++ )
			t1.addNumber( i );

		std::cout << "Shortest span is : " << t1.shortestSpan() << std::endl;
		std::cout << "Longest span is : " << t1.longestSpan() << std::endl;
	}
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }
}



void runTests( void )
{
	std::cout << "\n #========================================[ TEST 1 ]========================================#\n"  << std::endl;
	{ test( 0 ); }
	std::cout << "\n #========================================[ TEST 2 ]========================================#\n"  << std::endl;
	{ test( 1 ); }
	std::cout << "\n #========================================[ TEST 3 ]========================================#\n"  << std::endl;
	{ test( 2 ); }
	std::cout << "\n #========================================[ TEST 4 ]========================================#\n"  << std::endl;
	{ test( 5 ); }
	std::cout << "\n #========================================[ TEST 4 ]========================================#\n"  << std::endl;
	{ test( 10000 ); }
	std::cout << "\n #=========================================[ END ]==========================================#\n" << std::endl;
}

int	main( void )
{ runTests(); }