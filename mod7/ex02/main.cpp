#include <iostream>

template < typename T > void print( T const &i ) { std::cout << i << std::endl; }

template < typename T > void iter( T *ptr, size_t len, void ( *f )( T const & ) )
{
	T *arr = reinterpret_cast< T * >( ptr );
	for ( size_t i = 0; i < len; i++ )
		f( arr[ i ]);
}

void runTests( void )
{
	std::cout << "\nO================================ TEST 1 ================================O\n"  << std::endl;
	{
		int arr[] = { 1, 2, 3, 4, 5 };
		iter( arr, 5, print);
	}
	std::cout << "\nO================================ TEST 2 ================================O\n"  << std::endl;
	{
		float arr[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
		iter( arr, 5, print);
	}
	std::cout << "\nO================================= END ==================================O\n\n" << std::endl;
}

int	main( void )
{
	runTests();
}