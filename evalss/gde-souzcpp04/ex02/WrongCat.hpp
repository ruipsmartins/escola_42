#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(std::string name);
        WrongCat();
        WrongCat(WrongCat const &src);
		WrongCat &operator=(WrongCat const &src);
        ~WrongCat();

        void makeSound() const;
};

#endif
