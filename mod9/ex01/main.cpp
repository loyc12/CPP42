#include <iostream>
#include "Calculator.hpp"
#include <deque>

char getNext( std::deque<char> *bank )
{
	char c = bank->front();
	bank->pop_front();
	return c;
}

int calculate( int ac, char **av )
{
	std::deque<char> bank ;
	Calculator calc;

	std::cout << "\nArguments : [ ";

	for ( int i = 1; i < ac; i++ )
	{
		std::string str = av[ i ];
		std::cout << str << ' ';

		if ( str.size() != 1 )
		{
			std::cerr << "\nInvalid Argument ( non-char ) : " << str << std::endl;
			return ( 1 );
		}

		calc.checkSymbol( str[ 0 ] );
		bank.push_back( str[ 0 ] );
	}

	std::cout << "] ( " << bank.size() << " args )\n" << std::endl;;

	calc.setValue( getNext( &bank ));

	while ( !bank.empty() )
	{
		char num = getNext( &bank );
		char sym = getNext( &bank );

		calc.calculate( num, sym );
	}

	std::cout << "Result : " << calc.getValue() << std::endl << std::endl;

	return (0);
}

int	main( int ac, char **av )
{
	if ( ac < 2 || ac % 2 != 0 )
	{
		std::cerr << "Usage : " << av[ 0 ] << " ./RPN N0 [ N1 O1 ] [ N2 O2 ] ..." << std::endl;
		return ( 1 );
	}
	try { return calculate( ac, av ); }
	catch ( std::exception &e ) { std::cerr << e.what(); };
	return ( 2 );
}