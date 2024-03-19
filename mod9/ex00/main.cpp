#include <iostream>
#include "Exchanger.hpp"
#include <map>

int	main( int ac, char **av )
{
	if ( ac != 2 ) { std::cerr << "\nUsage : ./btc '< table >'\n" << std::endl;  return ( 1 ); }

	Exchanger exchanger( false );

	try
	{
		std::string path = "./data.csv";
		exchanger.setDB( path );
	}
	catch ( std::exception &e ) { std::cerr << e.what() << std::endl;  return ( 2 ); }

	try
	{
		std::string path = av[1];
		exchanger.exchange( path );
	}
	catch ( std::exception &e ) { std::cerr << e.what() << std::endl;  return ( 3 ); }

	std::cout << std::endl;

	return ( 0 );
}