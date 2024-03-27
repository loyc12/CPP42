#include <iostream>
#include "BitcoinExchange.hpp"
#include <map>

int	main( int ac, char **av )
{
	if ( ac != 2 ) { std::cerr << "\nUsage : ./btc '< table >'\n" << std::endl;  return ( 1 ); }

	BitcoinExchange bitcoinexchange( false );

	try
	{
		std::string path = "./data.csv";
		bitcoinexchange.setDB( path );
	}
	catch ( std::exception &e ) { std::cerr << e.what() << std::endl;  return ( 2 ); }

	std::cout << std::endl;

	try
	{
		std::string path = av[1];
		bitcoinexchange.exchange( path );
	}
	catch ( std::exception &e ) { std::cerr << e.what() << std::endl;  return ( 3 ); }

	std::cout << std::endl;

	return ( 0 );
}