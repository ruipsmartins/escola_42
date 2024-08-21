/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:25:45 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:25:46 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    const Animal *a = new Animal();
    const Dog *b = new Dog();
    const Cat *c = new Cat();
    const Dog z ( *b );
    std::cout << a->getType() << " " << std::endl;
    std::cout << b->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    std::cout << z.getType() << " " << std::endl;
    a->makeSound();
    b->makeSound();
    c->makeSound();
    z.makeSound();

    const WrongAnimal *d = new WrongCat();
    std::cout << d->getType() << " " << std::endl;
    d->makeSound();

    delete a;
    delete b;
    delete c;
    delete d;
}
