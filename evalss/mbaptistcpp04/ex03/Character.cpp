#include "Character.hpp"

Character::Character() : _name(""), _unequipCount(0) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
        unequipped[i] = NULL;
    std::cout << "Default Character constructed.\n";
}

Character::Character(std::string const &name) : _name(name), _unequipCount(0) {
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
        unequipped[i] = NULL;
    std::cout << "Character " << _name << " constructed.\n";
}

Character::Character(const Character &other) : _name(other._name), _unequipCount(other._unequipCount) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    for (int i = 0; i < 100; i++) {
        if (other.unequipped[i])
            unequipped[i] = other.unequipped[i]->clone();
        else
            unequipped[i] = NULL;
    }
    std::cout << "Character copy constructor called.\n";
}

Character &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other._name;
        clearInventory();
        clearUnequipped();
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        for (int i = 0; i < 100; i++) {
            if (other.unequipped[i])
                unequipped[i] = other.unequipped[i]->clone();
            else
                unequipped[i] = NULL;
        }
        _unequipCount = other._unequipCount;
    }
    std::cout << "Character assigned.\n";
    return *this;
}

Character::~Character() {
    clearInventory();
    clearUnequipped();
    std::cout << "Character " << _name << " destructed.\n";
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if( inventory[i] == NULL) {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
        if (_unequipCount < 100) {
            unequipped[_unequipCount++] = inventory[idx];
            inventory[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
        inventory[idx]->use(target);
}

void Character::clearInventory() {
    for (int i = 0; i < 4; i++) {
        delete inventory[i];
        inventory[i] = NULL;
    }
}

void Character::clearUnequipped() {
    for (int i = 0; i < 100; i++) {
        delete unequipped[i];
        unequipped[i] = NULL;
    }
    _unequipCount = 0;
}
