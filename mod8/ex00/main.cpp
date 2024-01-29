#include "Template.hpp"

void tester()
{
	Template t1( "t1" );
	std::cout << "\n >>> Insert test here" << std::endl;
	std::cout << "     | type : s\n" << std::endl;
}

template <typename T>
void tester_T()
{
	TemplateT<T> t1( 0 );
	std::cout << "\n >>> Insert test here" << std::endl;
	std::cout << "     | type : " << typeid( T ).name() << '\n' << std::endl;
}

void runTests( void )
{
	std::cout << "\nO====================================[ TEST 1 ]====================================O\n"  << std::endl;
	{ tester(); }
	std::cout << "\nO====================================[ TEST 2 ]====================================O\n"  << std::endl;
	{ tester_T<int>(); }
	std::cout << "\nO====================================[ TEST 3 ]====================================O\n"  << std::endl;
	{ tester_T<float>(); }
	std::cout << "\nO====================================[ TEST 4 ]====================================O\n"  << std::endl;
	{ tester_T<double>(); }
	std::cout << "\nO=====================================[ END ]======================================O\n" << std::endl;
}

int	main( void )
{ runTests(); }