#include "Contact.hpp"

Contact::Contact()
{

	this->first_name = "UNINITIALIZED";
	this->last_name = "UNINITIALIZED";
	this->nick_name = "UNINITIALIZED";
	this->phone_number = "UNINITIALIZED";
	this->dark_secret = "UNINITIALIZED";
}
Contact::~Contact()
{
	return ;
}

void Contact::Init()
{
	std::cout << "Enter info for new phonebook entry" << std::endl << std::endl;

	this->first_name = get_input("First name : ");
	this->last_name = get_input("Last name : ");
	this->nick_name = get_input("Nickname : ");
	this->phone_number = get_input("Phone number : ");
	this->dark_secret = get_input("Darkest secret : ");

	std::cout << std::endl;
}

void Contact::Load(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->first_name = fn;
	this->last_name = ln;
	this->nick_name = nn;
	this->phone_number = pn;
	this->dark_secret = ds;
}

void Contact::Display() const
{
	std::cout << "| ";
	truncate_print(this->first_name);
	std::cout << " | ";
	truncate_print(this->last_name);
	std::cout << " | ";
	truncate_print(this->nick_name);
	std::cout << " |" << std::endl;
}

void Contact::GetInfo() const
{
	std::cout << "First name     : " << this->first_name << std::endl;
	std::cout << "Last name      : " << this->last_name << std::endl;
	std::cout << "Nick name      : " << this->nick_name << std::endl;
	std::cout << "Phone number   : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->dark_secret << std::endl;
}
