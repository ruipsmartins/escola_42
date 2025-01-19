#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "includes.hpp"
# include "Contact.hpp"


class PhoneBook
{
    private:
        Contact contacts[8];
        int contactcount;

    public:
        PhoneBook(void);
        ~PhoneBook();
        void ADDContact(void);
        void SEARCHContact(void) const;

};

#endif