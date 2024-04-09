#include "MutantStack.hpp"

template <typename T>
void test()
{
	MutantStack<T> mstack;

	mstack.push((T)34);
	mstack.push((T)73);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push((T)63);
	mstack.push((T)55);
	mstack.push((T)77);

	//[...]

	mstack.push((T)48);

	typename MutantStack<T>::iterator it = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << (T)*it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<T> s(mstack);
}


void runTests( void )
{
	std::cout << "\n #========================================[ TEST 1 ]========================================#\n" << std::endl;
	{ test<int>(); }
	std::cout << "\n #========================================[ TEST 2 ]========================================#\n" << std::endl;
	{ test<char>(); }
	std::cout << "\n #========================================[ TEST 3 ]========================================#\n" << std::endl;
	{ test<float>(); }
	std::cout << "\n #=========================================[ END ]==========================================#\n" << std::endl;
}

int	main( void )
{ runTests(); }