#include "Foo.hpp"

void test()
{
	Foo t1( "zero" );
	std::cout << "\n >>> Insert test here" << std::endl;
	std::cout << "     | type : s" << std::endl;

	std::cout << "     | name : " << t1.getName() << std::endl << std::endl;
}

template <typename T>
void test_T()
{
	Foo_T<T> t1( 42 );
	std::cout << "\n >>> Insert test here" << std::endl;
	std::cout << "     | type : " << typeid( T ).name() << std::endl;

	std::cout << "     | bar  : " << t1.getBar() << std::endl << std::endl;
}

void runTests( void )
{
	std::cout << "\n #========================================[ TEST 1 ]========================================#\n" << std::endl;
	{ test(); }
	std::cout << "\n #========================================[ TEST 2 ]========================================#\n" << std::endl;
	{ test_T<int>(); }
	std::cout << "\n #========================================[ TEST 3 ]========================================#\n" << std::endl;
	{ test_T<float>(); }
	std::cout << "\n #========================================[ TEST 4 ]========================================#\n" << std::endl;
	{ test_T<double>(); }
	std::cout << "\n #=========================================[ END ]==========================================#\n" << std::endl;
}

int	main( void )
{ runTests(); }