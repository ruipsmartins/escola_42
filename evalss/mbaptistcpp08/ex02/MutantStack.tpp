#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename Template>
MutantStack<Template>::MutantStack() : std::stack<Template>() {}

template <typename Template>
MutantStack<Template>::MutantStack(const MutantStack<Template> &other) : std::stack<Template>(other) {}

template <typename Template>
MutantStack<Template> &MutantStack<Template>::operator=(const MutantStack<Template> &other) {
    if (this != &other) {
        std::stack<Template>::operator=(other);
    }
    return *this;
}

template <typename Template>
MutantStack<Template>::~MutantStack() {}

template <typename Template>
typename MutantStack<Template>::iterator MutantStack<Template>::begin() {
    return this->c.begin();
}

template <typename Template>
typename MutantStack<Template>::iterator MutantStack<Template>::end() {
    return this->c.end();
}

template <typename Template>
typename MutantStack<Template>::const_iterator MutantStack<Template>::begin() const {
    return this->c.begin();
}

template <typename Template>
typename MutantStack<Template>::const_iterator MutantStack<Template>::end() const {
    return this->c.end();
}

#endif