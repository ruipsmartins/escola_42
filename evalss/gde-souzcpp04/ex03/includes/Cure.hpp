#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"
# include "./ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure(std::string const &type);
        Cure();
        Cure(Cure const &src);
        Cure &operator=(Cure const &src);
        ~Cure();
        
        Cure* clone() const;
        void use(ICharacter& target);
};

#endif

