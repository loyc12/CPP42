#include <iostream>

//#include <Contact.hpp>
//#include <PhoneBook.hpp>

std::string	get_input(std::string message)
{
	std::cout << message;

	std::string	input;
	std::getline(std::cin, input);

	for (unsigned long i = 0; i < input.length(); i++)
        input[i] = std::toupper(input[i]);

	if (input.empty()) return (get_input(message)); //loops until the line has something in it
	return (input);
}


void	add_contact(void)
{
	std::cout << "Enter info for new phonebook entry" << std::endl;

	std::string	first_name = get_input("First name : ");
	std::string	last_name = get_input("Last name : ");
	std::string	phone_number = get_input("Phone number : ");
	std::string	nick_name = get_input("Nickname : ");

	//add contact to phonebook

	return ;
}

void	list_contacts(void)
{

	//list contacts from phonebook

	//ask for index

	//list it in its entirety

}

int main(void)
{
	std::string input;

	while (true)
	{
		input = get_input("Enter a command : ");
		if (!input.compare("EXIT")) return EXIT_SUCCESS;
		else if (!input.compare("ADD")) add_contact();
		else if (!input.compare("SEARCH")) list_contacts();
		else std::cout << "INVALID COMMAND" << std::endl;
	}
}
