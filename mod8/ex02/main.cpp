#include "MutantStack.hpp"

template <typename T>
void test()
{
	MutantStack<T> mstack;

	mstack.push((T)5);
	mstack.push((T)17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push((T)3);
	mstack.push((T)5);
	mstack.push((T)737);

	//[...]

	mstack.push(0);

	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;
	std::stack<T> s(mstack);
}


void runTests( void )
{
	std::cout << "\n #========================================[ TEST 1 ]========================================#\n"  << std::endl;
	{ test<int>(); }
	std::cout << "\n #========================================[ TEST 1 ]========================================#\n"  << std::endl;
	{ test<char>(); }
	std::cout << "\n #=========================================[ END ]==========================================#\n" << std::endl;
}

int	main( void )
{ runTests(); }