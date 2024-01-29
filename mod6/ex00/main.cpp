#include <iostream>
#include "ScalarConverter.hpp"


void	test( void )
{
	std::cout << "\nO================================ TEST 1 ================================O\n"  << std::endl;
	{

	}
	std::cout << "\nO================================ TEST 2 ================================O\n"  << std::endl;
	{

	}
	std::cout << "\nO================================= END ==================================O\n\n" << std::endl;
}

int		main( int ac, char **av )
{
	if ( ac != 2 ) { std::cout << "Usage: ./scalar [string]" << std::endl;  return 1; }
	if ( av[1][0] == '\0' ) { std::cout << "Error: empty string" << std::endl;  return 1; }

	ScalarConverter	scalar = ScalarConverter( av[ 1 ]);

	std::cout << scalar << std::endl;
}