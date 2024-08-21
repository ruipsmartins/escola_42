
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	public:
		Contact(void);
		~Contact(void);
	
		static int	nbr_contacts;
		void		add_new(void);
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nname(void) const;
		std::string	get_nbr(void) const;
		std::string	get_secret(void) const;

	private:
		std::string	check_nbr(std::string nbr) const;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
};

#endif
