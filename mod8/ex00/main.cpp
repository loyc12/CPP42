#include "easyfind.hpp"

template <typename T>
void tester_T()
{
	T c1;
	c1.push_back( 1 );
	c1.push_back( 2 );
	c1.push_back( 3 );

	std::cout << "\n >>> Insert test here" << std::endl;
	std::cout << "     | type : " << typeid( T ).name() << '\n' << std::endl;

	easyfind( c1, 2 );
}

void runTests( void )
{
	std::cout << "\nO====================================[ TEST 1 ]====================================O\n"  << std::endl;
	{ tester_T< std::list<int> >(); }
	std::cout << "\nO====================================[ TEST 2 ]====================================O\n"  << std::endl;
	{ tester_T< std::deque<int> >(); }
	std::cout << "\nO====================================[ TEST 3 ]====================================O\n"  << std::endl;
	{ tester_T< std::set<int> >(); }
	std::cout << "\nO====================================[ TEST 4 ]====================================O\n"  << std::endl;
	{ tester_T< std::vector<int> >(); }
	std::cout << "\nO=====================================[ END ]======================================O\n" << std::endl;
}

int	main( void )
{ runTests(); }