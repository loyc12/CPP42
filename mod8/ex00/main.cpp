#include "easyfind.hpp"

<<<<<<< HEAD
void testVec()
{
	std::vector<int> c;
	try
	{
		c.push_back( 1 );
		c.push_back( 2 );
		c.push_back( 3 );

		easyfind( c, 2 );
	}
	catch ( std::exception & e )
	{
		std::cout << "Error : " << e.what() << std::endl;
		return;
	}

}

void testList()
{
	std::list<int> c;
	try
	{
		c.push_back( 1 );
		c.push_back( 2 );
		c.push_back( 3 );

		easyfind( c, 2 );
	}
	catch ( std::exception & e )
	{
		std::cout << "Error : " << e.what() << std::endl;
		return;
	}

}

void testStack()
{
	std::stack<int> c;
	try
	{
		c.push( 1 );
		c.push( 2 );
		c.push( 3 );

		easyfind( c, 2 );
	}
	catch ( std::exception & e )
	{
		std::cout << "Error : " << e.what() << std::endl;
		return;
	}

}

void testDeque()
{
	std::deque<int> c;
	try
	{
		c.push_back( 1 );
		c.push_back( 2 );
		c.push_back( 3 );

		easyfind( c, 2 );
	}
	catch ( std::exception & e )
	{
		std::cout << "Error : " << e.what() << std::endl;
		return;
	}

}

void testQueue()
{
	std::queue<int> c;
	try
	{
		c.push( 1 );
		c.push( 2 );
		c.push( 3 );

		easyfind( c, 2 );
	}
	catch ( std::exception & e )
	{
		std::cout << "Error : " << e.what() << std::endl;
		return;
	}

}

void testPrioQ()
{
	std::priority_queue<int> c;
	try
	{
		c.push( 1 );
		c.push( 2 );
		c.push( 3 );

		easyfind( c, 2 );
	}
	catch ( std::exception & e )
	{
		std::cout << "Error : " << e.what() << std::endl;
		return;
	}

}

void runTests( void )
{
	std::cout << "\n O========================================[ TEST 1 ]========================================O\n"  << std::endl;
	{ testVec(); }
	std::cout << "\n O========================================[ TEST 2 ]========================================O\n"  << std::endl;
	{ testList(); }
	std::cout << "\n O========================================[ TEST 3 ]========================================O\n"  << std::endl;
	{ testDeque(); }
	std::cout << "\n O========================================[ TEST 4 ]========================================O\n"  << std::endl;
	{ testStack(); }
	std::cout << "\n O========================================[ TEST 5 ]========================================O\n"  << std::endl;
	{ testQueue(); }
	std::cout << "\n O========================================[ TEST 6 ]========================================O\n"  << std::endl;
	{ testPrioQ(); }
	std::cout << "\n O=========================================[ END ]==========================================O\n" << std::endl;
=======
void runTests( void )
{
	std::cout << "\nO====================================[ TEST 1 ]====================================O\n"  << std::endl;
	{ test< std::vector<int> >( 3, 2 ); }
	std::cout << "\nO====================================[ TEST 2 ]====================================O\n"  << std::endl;
	{ test< std::list<int> >( 3, 2 ); }
	std::cout << "\nO====================================[ TEST 3 ]====================================O\n"  << std::endl;
	{ test< std::deque<int> >( 3, 2 ); }
	std::cout << "\nO====================================[ TEST 4 ]====================================O\n"  << std::endl;
	{ test< std::vector<int> >( 3, 4 ); }
	std::cout << "\nO====================================[ TEST 5 ]====================================O\n"  << std::endl;
	{ test< std::vector<int> >( 0, 2 ); }
	std::cout << "\nO=====================================[ END ]======================================O\n" << std::endl;
>>>>>>> tmp
}

int	main( void )
{ runTests(); }