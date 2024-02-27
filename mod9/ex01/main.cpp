#include "Calculator.hpp"

void test()
{
	try
	{
		Calculator c;
		c.calculate('+', '9');
		c.calculate('-', '2');
		c.calculate('*', '4');
		c.calculate('/', '4');
		c.calculate('%', '3');

		std::cout << "\n RESULT == " << c << std::endl << std::endl;
	}
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }
}

void runTests( void )
{
	std::cout << "\n #========================================[ TEST 1 ]========================================#\n"  << std::endl;
	{ test(); }
	std::cout << "\n #========================================[ TEST 2 ]========================================#\n"  << std::endl;
	{

	}
	std::cout << "\n #=========================================[ END ]==========================================#\n" << std::endl;
}

int calc( int ac, char **av)
{
	try
	{
		Calculator c;

		if ( ac < 2 )
		{

		}
			std::cerr << "Usage: " << av[0] << " num num opp [ num opp ] ..." << std::endl;
		return (1);

		if ( av[1][1] != '\0' )
			goto errend;

		c.setValue( av[1][0] );

		for ( int i = 2; i <= ac; i += 2 )
		{
			std::cout << " > " << av[i] << " < " << std::endl;

			if ( av[i][1] != '\0' || av[i][1 + 1] != '\0')
				goto errend;

			c.calculate( av[i][0], av[i + 1][0] );
		}

		std::cout << c << std::endl;
		return (0);
	}
	catch (std::exception &e) { std::cerr << e.what() << std::endl; }

	errend:

	std::cerr << "Encountered an error" << std::endl;

	return (1);
}


int	main( int ac, char **av)
{
	//runTests( );

	return ( calc( ac, av ) );
}