#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "./Animal.hpp"
# include "./Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;

    public:
        Cat(std::string name);
        Cat();
        Cat(Cat const &src);
		Cat &operator=(Cat const &src);
        ~Cat();

        void makeSound() const;
};

#endif

