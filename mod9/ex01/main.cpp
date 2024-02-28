#include <iostream>
#include "Calculator.hpp"
#include <deque>

char getNextChar( std::deque<char> *bank )
{
	char c = bank->front();
	bank->pop_front();
	return c;
}

int getXprSize( char *arg )
{
	int i = 0;
	int size = 1;

	while ( arg[ i ] == ' ' ) // skip leading spaces
		i++;

	while ( arg[ i ] != '\0' )
		if ( arg[ i++ ] == ' ' )
		{
			while ( arg[ i ] == ' ' ) // skip multiple spaces
				i++;
			if ( arg[ i ] != '\0' ) // skip trailing spaces
				size++;
		}
	return size;
}

void splitStr( char *in, std::string *out)
{
	int i = 0;

	char *arg = strtok( in, " " );
	while ( arg != NULL )
	{
		out[ i ] = ( std::string )arg;
		arg = strtok( NULL, " " );
		i++;
	}
}

int calculate( int n, std::string *in )
{
	std::deque<char> bank ;
	Calculator calc;

	std::cout << "\nArguments : [ ";

	for ( int i = 0; i < n; i++ )
	{
		std::cout << in[ i ] << " ";

		if ( in[ i ].size() != 1 )
		{
			std::cerr << "... ]\n\nInvalid Argument : " << in[ i ] << " ( multiple characters )\n" << std::endl;
			return ( 4 );
		}

		calc.checkSymbol( in[ i ][ 0 ] );
		bank.push_back( in[ i ][ 0 ] );
	}

	std::cout << "] ( " << bank.size() << " args )" << std::endl;;

	calc.setValue( getNextChar( &bank ));

	while ( !bank.empty() )
	{
		char num = getNextChar( &bank );
		char sym = getNextChar( &bank );

		calc.calculate( num, sym );
	}

	std::cout << "\nResult : " << calc.getValue() << "\n" << std::endl;

	return (0);
}

int	main( int ac, char **av )
{
	if ( ac < 2 )
	{
		std::cerr << "\nUsage : ./RPN '< expression >' OR ./RPN N0 [ N1 O1 ] [ N2 O2 ] ...\n" << std::endl;
		return ( 1 );
	}

	std::string *xpr;
	int size = ac - 1;

	if ( ac == 2 )
	{
		size = getXprSize( av[ 1 ] );

		if ( size == 0 )
			return ( 1 );
		xpr = new std::string[ size ];

		splitStr( av[ 1 ], xpr );
	}
	else
	{
		xpr = new std::string[ size ];

		for ( int i = 1; i < ac; i++ )
			xpr[ i - 1 ] = ( std::string )av[ i ];
	}

	if ( size % 2 == 0 )
	{
		std::cerr << "\nInvalid number of arguments : " << size << " ( must be odd )\n"  << std::endl;
		return ( 2 );
	}

	try { return calculate( size, xpr ); }
	catch ( std::exception &e ) { std::cerr << e.what(); };
	return ( 3 );
}