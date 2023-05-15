#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
}
PhoneBook::~PhoneBook()
{
	return ;
}

void PhoneBook::AddContact(void)
{
	Contact	new_contact;

	new_contact.Init();

	if (contact_count >= BookSize)
	{
		for (int i = 0; i < BookSize - 1; i++)
			this->contacts[i] = this->contacts[i + 1];
		contact_count = BookSize - 1;

		std::cout << "Removed previous contact !" << std::endl;
	}
	this->contacts[contact_count] = new_contact;
	contact_count++;

	std::cout << "Added new contact !" << std::endl << std::endl;
}

void PhoneBook::SearchContacts(void) const
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

//adds the following dummy contacts (for testing purposes)
void PhoneBook::FillContacts(void)
{
	this->contacts[0].Load("Alice", "Allard", "Lili", "0", "Aimes beaucoup trop le hockey");
	this->contacts[1].Load("Bob", "Bergeron", "Bobby", "1", "N'aime pas son surnom");
	this->contacts[2].Load("Clarence", "Caron", "Carré", "10", "A déjà roulé sur une couleuvre en vélo");
	this->contacts[3].Load("Daniel", "Dupré-Deschamps", "Dan", "11", "A une famille secrete");
	this->contacts[4].Load("Étienne", "Érrant", "Titiènne", "100", "Torture des mouches");
	this->contacts[5].Load("Fabienne", "Félicité", "Fabi", "101", "Souhaite que sa pire ennemie soufre");
	this->contacts[6].Load("Gaétan", "Gastonguay", "Gaston", "110", "A déjà trouvé un cadavre dans les bois");
	this->contacts[7].Load("Héliot", "Hébert", "Éli", "111", "A déjà enterré un cadavre dans les bois");
	//this->contacts[8].Load("Isabelle", "Irène", "Iza", "1000", "Vote secretement pour le parti vert");
	//this->contacts[9].Load("Justin", "Jaspar", "Jas", "1001", A déjà frappé quelqu'un en voiture);
	this->contact_count = BookSize;

	std::cout << "Filled book with dummy contacts !" << std::endl << std::endl;
}

//the listing part of SEARCH, without asking for an index (for testing purposes)
void PhoneBook::ListContacts(void) const
{
	if (this->contact_count > 0)
	{
		std::cout << "  #   First Name   Last Name    Nickname" << std::endl;
		std::cout << "o - o ---------- o ---------- o ---------- o" << std::endl;
		for (int i = this->contact_count - 1; i >= 0; i--)
		{
			std::cout << "| " << i << " ";
			this->contacts[i].Display();
		}
		std::cout << "o - o ---------- o ---------- o ---------- o" << std::endl;
	}
	else
	{
		std::cout << "o ------- o" << std::endl;
		std::cout << "|  Empty  |" << std::endl;
		std::cout << "o ------- o" << std::endl;
	}
	std::cout << std::endl;
}

//clears all contact info (for testing purposes)
void PhoneBook::ClearContacts(void)
{
	Contact	empty_contact;

	for (int i = 0; i < BookSize; i++)
		this->contacts[i] = empty_contact;
	this->contact_count = 0;

	std::cout << "Cleared book's contacts !" << std::endl << std::endl;
}
