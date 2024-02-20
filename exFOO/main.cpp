#include "Foo.hpp"

void test()
{
	Foo t1( "t1" );
	std::cout << "\n >>> Insert test here" << std::endl;
	std::cout << "     | type : s\n" << std::endl;
}

template <typename T>
void test_T()
{
	Foo_T<T> t1( 0 );
	std::cout << "\n >>> Insert test here" << std::endl;
	std::cout << "     | type : " << typeid( T ).name() << '\n' << std::endl;
}

void runTests( void )
{
	std::cout << "\n #========================================[ TEST 1 ]========================================#\n"  << std::endl;
	{ test(); }
	std::cout << "\n #========================================[ TEST 2 ]========================================#\n"  << std::endl;
	{ test_T<int>(); }
	std::cout << "\n #========================================[ TEST 3 ]========================================#\n"  << std::endl;
	{ test_T<float>(); }
	std::cout << "\n #========================================[ TEST 4 ]========================================#\n"  << std::endl;
	{ test_T<double>(); }
	std::cout << "\n #=========================================[ END ]==========================================#\n" << std::endl;
}

int	main( void )
{ runTests(); }