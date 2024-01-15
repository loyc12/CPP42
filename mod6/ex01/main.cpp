#include <iostream>
#include "Data.hpp"

uintptr_t serialize( Data *ptr ) { return reinterpret_cast< uintptr_t >( ptr ); }

Data *deserialize( uintptr_t raw ) { return reinterpret_cast< Data * >( raw ); }

int	main(void)
{
	std::cout << "1 O================================================================O\n"  << std::endl;
	{
		Data *data1 = new Data;

		data1->text = "Hello World!";
		std::cout << "data->text: " << data1->text << std::endl;

		uintptr_t raw = serialize( data1 );
		std::cout << "raw: " << raw << std::endl;

		Data *data2 = deserialize( raw );
		std::cout << "data2->text: " << data2->text << std::endl;

		delete data1;

	}
	std::cout << "\nE O================================================================O\n" << std::endl;
}