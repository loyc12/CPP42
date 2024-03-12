#include <iostream>
#include "Exchanger.hpp"
#include <map>

int	main( int ac, char **av )
{
	if ( ac != 2 )
	{
		std::cerr << "\nUsage : ./btc '< table >'\n" << std::endl;
		return ( 1 );
	}

	std::string path = av[1];
	Exchanger exchanger( path );

	std::cout << exchanger << std::endl;

	return ( 3 );
}

/*
function main:
    input_data = parse_input_file(input_file)
    conversion_rates = parse_csv_database(csv_file)
    for each date, bitcoin_amount in input_data:
        usd_value = conversion_rates[date]
        converted_amount = bitcoin_amount * usd_value
        print(date, converted_amount)

function parse_input_file:
    // Open the file
    // For each line in the file:
        // Split the line into date and bitcoin_amount
        // Store the date and bitcoin_amount in a data structure
    // Return the data structure

function parse_csv_database:
    // Open the file
    // For each line in the file:
        // Split the line into date and usd_value
        // Store the date and usd_value in a map
    // Return the map
*/

/*
class Exchanger {
    private:
        std::map<std::string, double> rates;

    public:
        Exchanger(std::string path) {
            parseCSV(path);
        }

        double convert(std::string date, double bitcoinAmount) {
            double usdValue = rates[date];
            return bitcoinAmount * usdValue;
        }

    private:
        void parseCSV(std::string path) {
            // Open the file
            // For each line in the file:
                // Split the line into date and usdValue
                // Store the date and usdValue in the map
        }

    friend std::ostream& operator<<(std::ostream& os, const Exchanger& exchanger) {
        // Iterate over the map and print each date/value pair
    }
};
*/