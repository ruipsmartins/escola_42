#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria *templates[4];
    
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria *m);
        virtual AMateria *createMateria(std::string const &type);

};

#endif