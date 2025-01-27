#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    protected:
        std::string _ideas[100];
    
    public:
        Brain();
        Brain(Brain const &src);
        Brain &operator=(Brain const &src);
        ~Brain();
        std::string getIdeas() const;
        //void setIdeas(std::string str) const;
};

#endif 
