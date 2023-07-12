#include "suplements.hpp"

//displays the allowed commands
void	welcome()
{
	std::cout << "o ----------------------------- o" << std::endl;
	std::cout << "|   Welcome to your Phonebook   |" << std::endl;
	std::cout << "|      Available  commands      |" << std::endl;
	std::cout << "|  HELP   : show this menu      |" << std::endl;
	std::cout << "|  ADD    : add a new contact   |" << std::endl;
	std::cout << "|  FILL   : add dummy contacts  |" << std::endl;
	std::cout << "|  CLEAR  : clear all contacts  |" << std::endl;
	std::cout << "|  LIST   : list all contacts   |" << std::endl;
	std::cout << "|  SEARCH : lookup a contact    |" << std::endl;
	std::cout << "|  EXIT   : close the program   |" << std::endl;
	std::cout << "o ----------------------------- o" << std::endl;
	std::cout << std::endl;
}

//asks for a user inputed string
std::string get_input(std::string message)
{
	return (get_input(message, false));
}

//asks for a user inputed string
std::string get_input(std::string message, bool capitalize)
{
	std::cout << message;

	std::string	input;
	std::getline(std::cin, input);

	if (!std::cin.eof() && !std::cin.bad())
	{
		if (input.empty())
			return (get_input(message, capitalize)); //loops until the line is non-empty
		if (capitalize)
		{
			for (unsigned long i = 0; i < input.length(); i++)
				input[i] = std::toupper(input[i]);
		}
		return (input);
	}
	else
	{
		std::cout << "! INPUT ERROR !" << std::endl;
		return ("ERROR");
	}
}

//prints only FIELD_LENGHT chars from a string, truncating with "." if needed
void truncate_print(std::string message)
{
	truncate_print(message, FIELD_LENGHT);
}

//prints only a given lenght of a string, truncating with "." if needed
void truncate_print(std::string message, int size)
{
	int	i = 0;
	int	offset = 0;
	int	isTruncated = 0;

	if (true_lenght(message) > size) //sets "truncation needed" flag
		isTruncated = 1;

	while (message[i] && (i - offset < size - isTruncated)) //compensates size for non-ascii (multi-byes) chars
	{
		while (message[i + 1] && (message[i + 1] & 0xc0) == 0x80) //avoids spliting multi-bytes chars
		{
			offset++; //counts non-char-starting bytes in the string
			i++;
		}
		i++; // counts all bytes in the string
	}

	manip_print(message, size + offset - isTruncated); //prints the message appropriately (isolates the iomanips)

	if (isTruncated)
		std::cout << ".";
}

//
void manip_print(std::string message, int size)
{
	if (message.length() > (unsigned long)size) //truncates the string if needed
		message = message.substr(0, size);

	std::cout << std::setfill(' ') << std::setw(size) << std::left;
	std::cout << message;
}

//finds the visual lenght of a string (counts multiple-bytes chars as one)
int true_lenght(std::string message)
{
	int lenght = 0;

	for (unsigned long i = 0; i < message.length(); i++)
	{
		if ((message[i] & 0xc0) != 0x80) //counts only starting bytes (deals with multi-bytes chars)
			lenght++;
	}
	return (lenght);
}
