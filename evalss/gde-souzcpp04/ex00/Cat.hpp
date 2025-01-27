#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "./Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(std::string name);
        Cat();
        Cat(Cat const &src);
		Cat &operator=(Cat const &src);
        ~Cat();

        void makeSound() const;
};

#endif

