#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "./AMateria.hpp"
# include "./IMateriaSource.hpp"

#define SIZE 4

class MateriaSource : public IMateriaSource
{
    private:
	    AMateria	*_inventory[SIZE];

    public:
        MateriaSource();
        MateriaSource(MateriaSource const &src);
        MateriaSource &operator=(MateriaSource const &src);
        ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};

#endif
