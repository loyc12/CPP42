#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include "suplements.hpp"

class	PhoneBook
{
	private:
		int	contact_count;
		Contact contacts[10];

	public:
		void AddContact(void);
		void ListContacts(void);
		void SearchContacts(void);
		void ClearContacts(void);
		void FillContacts();
};

#endif //PHONEBOOK_HPP
