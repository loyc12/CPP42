#include "suplements.hpp"

//displays the allowed commands
void	welcome()
{
	std::cout << "o ---------------------------- o" << std::endl;
	std::cout << "|  Welcome to your Phonebook!  |" << std::endl;
	std::cout << "|  Usage :                     |" << std::endl;
	std::cout << "|    ADD : adds new contact    |" << std::endl;
	//std::cout << "|    LIST : lists contacts     |" << std::endl;
	std::cout << "|    SEARCH : lookup a contact |" << std::endl;
	//std::cout << "|    CLEAR : removes contacts  |" << std::endl;
	std::cout << "o ---------------------------- o" << std::endl;
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

	if (capitalize)
	{
		for (unsigned long i = 0; i < input.length(); i++)
        	input[i] = std::toupper(input[i]);
	}

	if (input.empty()) return (get_input(message, capitalize)); //loops until the line has something in it
	return (input);
}

//prints only 10 chars from a string, remplacing the final char by a '.' if there is more after
void truncate_print(std::string message)
{
	truncate_print(message, 10);
}

//prints only a given lenght of a string, remplacing the final char by a '.' if there is more after
void truncate_print(std::string message, int size)
{
	int i = 0;

	if (true_lenght(message) <= size)
	{
		std::cout << message;
		i = true_lenght(message);
		while (i < size)
		{
			std::cout << " ";
			i++;
		}
	}
	else
	{
		int	offset = 0; //counts non-char-starting bytes ub the string

		while ((i - offset) < (size - 1))
		{
			std::cout << message[i];
			while ((message[i + 1] & 0xc0) == 0x80) //allows multiple-bytes chars to be printed normally
			{
				std::cout << message[++i];
				offset++;
			}
			i++;
		}
		std::cout << ".";
	}
}

//finds the visual lenght of a string (counts multiple-bytes chars as one)
int true_lenght(std::string message)
{
	int lenght = 0;

	for (unsigned long i = 0; i < message.length(); i++)
	{
		lenght += (message[i] & 0xc0) != 0x80;
	}
	return lenght;
}
