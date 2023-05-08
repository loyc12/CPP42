#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include "suplements.hpp"

# define BookSize 8 //max number of contacts phonebook can store (breaks above 10)

class	PhoneBook
{
	private:
		Contact contacts[BookSize];
		int	contact_count;

	public:
		PhoneBook();
		~PhoneBook();

		void AddContact(void);
		void SearchContacts(void) const;

		void FillContacts();
		void ListContacts(void) const;
		void ClearContacts(void);
};

#endif //PHONEBOOK_HPP
