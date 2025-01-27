#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal(std::string name);
        Animal();
        Animal(Animal const &src);
		Animal &operator=(Animal const &src);
        virtual ~Animal();

        std::string getType() const;
        void setType(std::string str);
        virtual void makeSound() const;
};

#endif