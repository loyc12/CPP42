#include <iostream>
#include "Array.hpp"

#define MAX_VAL 8
#define MAX_RAND 256

template < typename T >
T getRandValue( void )
{
	T value;

	// If char, make sure it's a printable character
	if ( typeid( T ) == typeid( char )) { value = 33 + ( rand() % 94 ); }
	else								  value = rand() % MAX_RAND;

	// If decimal, add a decimal part
	if ( typeid( T ) == typeid( float ) || typeid( T ) == typeid( double ))
		value += ( rand() % 100 ) / 100.0;

	return value;
}
template < typename T >
void tryIndexAccess( Array<T> &array, int index )
{
	try {
		std::cout << "\nTrying to access index " << index << std::endl;
		T value = array[ index ];
		std::cout << "Value : " << value << std::endl;
		array[ index ] = value;
	} catch( const std::exception &e ) { std::cerr << e.what() << '\n'; }
}

template <typename T>
void tester()
{
    Array<T> numbers( MAX_VAL );
    T* mirror = new T[ MAX_VAL ];

	std::cout << "\n >>> Testing with type : " << typeid( T ).name() << std::endl;
	std::cout << "     | Arrays of size " << numbers.size() << std::endl;
	std::cout << "     | Values between 0 and " << MAX_RAND << std::endl;

    srand( time( NULL ));
	std::cout << "\nArray : " << numbers << std::endl;

    for ( int i = 0; i < MAX_VAL; i++ )
    {
		T value = getRandValue<T>();

        numbers[ i ] = ( T )value;
        mirror[ i ] = ( T )value;
    }
	std::cout << "Array : " << numbers << std::endl << std::endl;

    //SCOPE
    {
		Array<T> tmp( 4 );
        Array<T> test( tmp );
		test = numbers;
		tmp = test;
    }

    for ( int i = 0; i < MAX_VAL; i++ )
    {
        if ( mirror[ i ] != numbers[ i ])
        {
            std::cerr << "\nvalues do not match originals !" << std::endl;
            return;
        }
    }

	tryIndexAccess( numbers, -MAX_VAL - 1 );
	tryIndexAccess( numbers, -MAX_VAL );
	tryIndexAccess( numbers, -( MAX_VAL / 2 ));
	tryIndexAccess( numbers, -1 );
	tryIndexAccess( numbers, 2 );
	tryIndexAccess( numbers, MAX_VAL / 2 );
	tryIndexAccess( numbers, MAX_VAL - 1 );
	tryIndexAccess( numbers, MAX_VAL );

	std::cout << "\nTrying to reassign values forwards" << std::endl;
    for ( int i = 0; i < MAX_VAL; i++ ) { numbers[ i ] = getRandValue<T>(); }
	std::cout << "Array : " << numbers << std::endl;

	std::cout << "\nTrying to reassign values backwards" << std::endl;
    for ( int i = 0; i > -MAX_VAL; --i ) { numbers[ i ] = getRandValue<T>(); }
	std::cout << "Array : " << numbers << std::endl;

    delete [] mirror;

	std::cout << std::endl;
}

void runTests( void )
{
	std::cout << "\n O========================================[ TEST 1 ]========================================O\n"  << std::endl;
	{ tester<char>(); }
	std::cout << "\n O========================================[ TEST 2 ]========================================O\n"  << std::endl;
	{ tester<int>(); }
	std::cout << "\n O========================================[ TEST 3 ]========================================O\n"  << std::endl;
	{ tester<float>(); }
	std::cout << "\n O========================================[ TEST 4 ]========================================O\n"  << std::endl;
	{ tester<double>(); }
	std::cout << "\n O=========================================[ END ]==========================================O\n" << std::endl;
}

int	main( void )
{ runTests(); }