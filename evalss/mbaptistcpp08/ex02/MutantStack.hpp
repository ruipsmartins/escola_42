#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <stdexcept>

template <typename Template>
class MutantStack : public std::stack<Template>
{
    public:
        typedef typename std::stack<Template>::container_type::iterator iterator;
        typedef typename std::stack<Template>::container_type::const_iterator const_iterator;

        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        Template& top() {
        if (std::stack<Template>::empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return std::stack<Template>::c.back();
        }

        void pop() {
        if (std::stack<Template>::empty()) {
            throw std::out_of_range("Stack is empty");
        }
        std::stack<Template>::c.pop_back();
        }

};

#include "MutantStack.tpp"

#endif