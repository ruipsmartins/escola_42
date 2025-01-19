# ifndef CONCTACT_HPP
#define CONCTACT_HPP

# include "includes.hpp"

class Contact
    {
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        std::string get_firstname(void) const;
        std::string get_lastname(void) const;
        std::string get_nickname(void) const;
        std::string get_phone_number(void) const;
        std::string get_darkest_secret(void) const;
        std::string get_first_name9(void) const;
        std::string get_last_name9(void) const;
        std::string get_nickname9(void) const;
        Contact(void);
		~Contact(void);
        void get_input(std::string *input, const std::string message);
        void ADDContact(void);


    };

# endif