#include "PhoneBook.hpp"

void PhoneBook::AddContact(void)
{
	Contact	new_contact;

	new_contact.Init();

	if (contact_count == 10)
	{
		for (int i = 0; i < 9; i++)
			this->contacts[i] = this->contacts[i + 1];
		contact_count--;
	}
	if (contact_count < 10)
	{
		this->contacts[contact_count] = new_contact;
		contact_count++;
	}

	std::cout << "Added new contact !" << std::endl << std::endl;
}

void PhoneBook::SearchContacts(void)
{

	ListContacts();

	if (this->contact_count > 0)
	{
		std::string	input;

		input = get_input("Index : ");

		if (input.length() == 1 && '0' <= input[0] && input[0] - '0' < this->contact_count)
		{
			int	i;

			i = input[0] - '0';
			std::cout << std::endl;
			this->contacts[i].GetInfo();
		}
		else
			std::cout << std::endl << "! INVALID INDEX !" << std::endl;
		std::cout << std::endl;
	}
}

void PhoneBook::ListContacts(void)
{
	if (this->contact_count > 0)
	{
		std::cout << "o - o ---------- o ---------- o ---------- o ---------- o" << std::endl;
		for (int i = this->contact_count - 1; i >= 0; i--)
		{
			std::cout << "| " << i << " ";
			this->contacts[i].Display();
		}
		std::cout << "o - o ---------- o ---------- o ---------- o ---------- o" << std::endl;
	}
	else
		std::cout << "! PHONEBOOK IS EMPTY !" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::ClearContacts(void)
{
	Contact	empty_contact;

	for (int i = 0; i < 10; i++)
		this->contacts[i] = empty_contact;
	this->contact_count = 0;

	std::cout << "Cleared all contacts !" << std::endl << std::endl;
}

void PhoneBook::FillContacts(void)
{
	this->contacts[0].Load("Alice", "Allard", "0", "Lili");
	this->contacts[1].Load("Bob", "Bergeron", "1", "Bobby");
	this->contacts[2].Load("Clarence", "Caron", "2", "Carré");
	this->contacts[3].Load("Daniel", "Dupré-Deschamps", "3", "Dan");
	this->contacts[4].Load("Étienne", "Érrant", "4", "Titiènne");
	this->contacts[5].Load("Fabienne", "Félicité", "5", "Fabi");
	this->contacts[6].Load("Gétan", "Gastonguay", "6", "Gaston");
	this->contacts[7].Load("Héliot", "Hébert", "7", "Éli");
	this->contacts[8].Load("Isabelle", "Irène", "8", "Iza");
	this->contacts[9].Load("Justin", "Jaspar", "9", "Jas");
	this->contact_count = 10;
}
