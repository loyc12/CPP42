#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "suplements.hpp"

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_phone_number;
		std::string	_nick_name;

	public:
		Contact();
		~Contact();
		void Init();
		void Load(std::string _fn, std::string _ln, std::string _pn, std::string _nn);
		void Display();
		void GetInfo();
};

#endif //CONTACT_HPP