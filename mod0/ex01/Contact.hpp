#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "suplements.hpp"

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	dark_secret;

	public:
		Contact();
		~Contact();
		void Init();
		void Load(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void Display() const;
		void GetInfo() const;
};

#endif //CONTACT_HPP