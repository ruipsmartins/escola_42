
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		add_cont(void);
		void		search_cont(void) const;
		void		show_cont(void) const;

	private:
		std::string	truncate(std::string str) const;
		Contact		_list[8];
};

#endif
