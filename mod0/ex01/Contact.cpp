#include <iostream>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	phone_number;
		std::string	nick_name;

	public:
		Contact(void)
		{
			return ;
		}

		~Contact(void)
		{
			return ;
		}

		std::string GetFirstName(void)
		{
			return (first_name);
		}
		std::string GetLastName(void)
		{
			return (last_name);
		}
		std::string GetPhoneNumber(void)
		{
			return (phone_number);
		}
		std::string GetNickName(void)
		{
			return (nick_name);
		}
};
