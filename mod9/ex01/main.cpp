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

	Calculator calc;
	calc.debug( true );

	std::cout << "\nFormula : ";

	for ( int j = 0; j < n; j++ )
		std::cout << in[ j ][ 0 ] << " ";

	std::cout << std::endl << std::endl;

	for ( int i = 0; i < n; i++ )
		calc.push( in[ i ] );

	std::cout << std::endl << "Result : " << calc.getResult() << std::endl;;

	return (0);
}

int	main( int ac, char **av )
{
	if ( ac < 2 )
	{
		std::cerr << "\nUsage : ./RPN '< expression >' OR ./RPN n0 [ n1 o1 ] [ n2 o2 ] ...\n" << std::endl;
		std::cerr << "PS : if using the second method, be sure to put \\ before any *\n" << std::endl;
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

	if ( size <= 2 )
	{
		std::cerr << "\nInvalid number of arguments : must be at least 3\n"  << std::endl;
		return ( 2 );
	}

	try { return calculate( size, xpr ); }
	catch ( std::exception &e ) { std::cerr << e.what(); };
	return ( 0 );
}