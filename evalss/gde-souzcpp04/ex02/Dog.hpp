#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "./Animal.hpp"
# include "./Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;

    public:
        Dog(std::string name);
        Dog();
        Dog(Dog const &src);
		Dog &operator=(Dog const &src);
        ~Dog();

        void makeSound() const;
};

#endif
