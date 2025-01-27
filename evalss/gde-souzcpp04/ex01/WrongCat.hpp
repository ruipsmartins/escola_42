#ifndef C7825E9D_CE64_4626_9FF8_248B99F05C2B
#define C7825E9D_CE64_4626_9FF8_248B99F05C2B
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


#endif /* C7825E9D_CE64_4626_9FF8_248B99F05C2B */
