#include "Contact.hpp"

Contact::Contact()
{
	return ;
}
Contact::~Contact()
{
	return ;
}

void Contact::Init()
{
	std::cout << "Enter info for new phonebook entry" << std::endl << std::endl;

	this->_first_name = get_input("First name : ");
	this->_last_name = get_input("Last name : ");
	this->_phone_number = get_input("Phone number : ");
	this->_nick_name = get_input("Nickname : ");

	std::cout << std::endl;
}

void Contact::Load(std::string _fn, std::string _ln, std::string _pn, std::string _nn)
{
	this->_first_name = _fn;
	this->_last_name = _ln;
	this->_phone_number = _pn;
	this->_nick_name = _nn;
}

void Contact::Display()
{
	std::cout << "| ";
	truncate_print(this->_first_name);
	std::cout << " | ";
	truncate_print(this->_last_name);
	std::cout << " | ";
	truncate_print(this->_phone_number);
	std::cout << " | ";
	truncate_print(this->_nick_name);
	std::cout << " |" << std::endl;
}

void Contact::GetInfo()
{
	std::cout << "First name   : " << this->_first_name << std::endl;
	std::cout << "Last name    : " << this->_last_name << std::endl;
	std::cout << "Phone Number : " << this->_phone_number << std::endl;
	std::cout << "Nick name    : " << this->_nick_name << std::endl;
}
