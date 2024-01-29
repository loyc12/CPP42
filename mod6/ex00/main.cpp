#include <iostream>
#include "ScalarConverter.hpp"


int		main( int ac, char **av )
{
	if ( ac != 2 ) { std::cout << "Usage: ./scalar [string]" << std::endl;  return 1; }
	if ( av[1][0] == '\0' ) { std::cout << "Error: empty string" << std::endl;  return 1; }

	ScalarConverter	scalar = ScalarConverter( av[ 1 ]);

	std::cout << scalar << std::endl;
}