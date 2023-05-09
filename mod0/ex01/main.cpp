#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "suplements.hpp"

int main(void)
{
	std::string input;
	PhoneBook	book;

	welcome();

	while (!std::cin.eof())
	{
		input = get_input("Enter a command : ", true);
		std::cout << std::endl;
		if (!input.compare("EXIT")) return EXIT_SUCCESS;
		else if (!input.compare("HELP")) welcome();
		else if (!input.compare("ADD")) book.AddContact();
		else if (!input.compare("FILL")) book.FillContacts();
		else if (!input.compare("CLEAR")) book.ClearContacts();
		else if (!input.compare("LIST")) book.ListContacts();
		else if (!input.compare("SEARCH")) book.SearchContacts();
		else std::cout << "! INVALID COMMAND !" << std::endl << std::endl;
	}
}
