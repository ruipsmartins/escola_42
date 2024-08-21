#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructed.\n";
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructed.\n";
    for(int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain assigned.\n";
    if(this != &other) {
        for(int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {}

void Brain::setIdea(int i, const std::string &idea) {
    if(i >= 0 && i < 100)
        _ideas[i] = idea;
}


std::string Brain::getIdea(int i) const {
    if(i >= 0 && i < 100)
        return _ideas[i];
    return "";
}