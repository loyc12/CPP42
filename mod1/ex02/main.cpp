#include <iostream>

//	how a reference works conceptually :
//	int VAR = 0;
//	#define REF static VAR

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string &ref = str;

//	both of these are functionally identical
//	td::string *ptr = &str;
	std::string *ptr = &ref;

	std::cout << "Adresses of : " << std::endl;
	std::cout << "STR : " << &str << std::endl;
	std::cout << "REF : " << &ref << std::endl;
	std::cout << "PTR : " << &ptr << std::endl;

	std::cout << std::endl;

	std::cout << "Values at : " << std::endl;
	std::cout << "STR : " << str << std::endl;
	std::cout << "DEF : " << ref << std::endl;
	std::cout << "PTR : " << ptr << std::endl;

	std::cout << std::endl;

	std::cout << "Values pointed to by : " << std::endl;
	std::cout << "STR : " << "N/A" << std::endl;
	std::cout << "DEF : " << "N/A" << std::endl;
	std::cout << "PTR : " << *ptr << std::endl;

	std::cout << std::endl;

	std::cout << "TL;DR: A reference is a shortcut to a given variable that can only be used to read, and never write to said variable." << std::endl;
	std::cout << "This means that any modification to the variable will also apply to the reference itself, as it is an alias, not a copy." << std::endl;
	std::cout << "In a way, a reference acts similarily to \'#define {REF} static {VAR}\' - at least conceptually - within the same scope." << std::endl;
	std::cout << "PS: From what I understand, during compilation, references generally get replaced by the variable itself" << std::endl;

	std::cout << std::endl;
}