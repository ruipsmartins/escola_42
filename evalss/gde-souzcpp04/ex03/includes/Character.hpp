#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"
# include "ICharacter.hpp"

# define SIZE 4

class Character : public ICharacter
{
    private:
	    std::string	_name;
        AMateria	*_inventory[SIZE + 1];
        AMateria	*_dump[(SIZE * 2) + 1];

    public:
        Character();
        Character(std::string const &name);
        Character(Character const &src);
        Character &operator=(Character const &src);
        virtual ~Character();

        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif
