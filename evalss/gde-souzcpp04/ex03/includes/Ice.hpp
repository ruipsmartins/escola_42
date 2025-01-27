#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice(std::string const &type);
        Ice();
        Ice(Ice const &src);
        Ice &operator=(Ice const &src);
        ~Ice();
        
        Ice* clone() const;
        void use(ICharacter& target);
};

#endif
