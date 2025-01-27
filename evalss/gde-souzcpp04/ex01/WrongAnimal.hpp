#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
    protected:
        std::string _type;

    public:
        WrongAnimal(std::string name);
        WrongAnimal();
        WrongAnimal(WrongAnimal const &src);
		WrongAnimal &operator=(WrongAnimal const &src);
        ~WrongAnimal();

        std::string getType() const;
        void setType(std::string str);
        virtual void makeSound() const;
};

#endif