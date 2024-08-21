#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; i++)
        if(other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
}


MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete templates[i];
            if (other.templates[i])
                templates[i] = other.templates[i]->clone();
            else
                templates[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] == NULL) {
            templates[i] = m;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++)
        if(templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    return NULL;
}
