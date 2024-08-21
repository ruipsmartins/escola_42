/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:19:51 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 08:51:35 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"

int main()
{
	{
		std::cout << "\n---STANDARD MAIN---" << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\n---CREATING DEEP COPIES---" << std::endl;
		Character *alex1 = new Character("alex");
		Character *bob1 = new Character(*alex1);
		std::cout << "alex:" << alex1->getName() << "  bob:" << bob1->getName() << std::endl;
		bob1->setName("bob");
		std::cout << "After new name" << std::endl;
		std::cout << "alex:" << alex1->getName() << "  bob:" << bob1->getName() << std::endl;
		delete alex1;
		delete bob1;

		Character *alex2 = new Character("alex");
		Character *bob2 = new Character(*alex2);
		*bob2 = *alex2;
		std::cout << "alex:" << alex2->getName() << "  bob:" << bob2->getName() << std::endl;
		bob2->setName("bob");
		std::cout << "After new name" << std::endl;
		std::cout << "alex:" << alex2->getName() << "  bob:" << bob2->getName() << std::endl;
		delete alex2;
		delete bob2;
		std::cout << "\n--------------------------" << std::endl;
	}
	{
		std::cout << "\n---CREATING MATERIA AND MAX VALUES---" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		std::cout << "\n-------------------------------------" << std::endl;
		delete src;
	}
	{
		std::cout << "\n---EQUIP, USE & UNEQUIP ACTIONS---\n" << std::endl;
		ICharacter *alex = new Character("alex");
		ICharacter *bob = new Character("bob");

		std::cout << std::endl;
		AMateria *cure1 = new Cure();
		AMateria *ice1 = new Ice();
		AMateria *cure2 = new Cure();
		AMateria *ice2 = new Ice();
		alex->equip(ice1);
		alex->equip(cure1);
		alex->equip(ice2);
		alex->equip(cure2);
		alex->use(0, *bob);
		alex->use(1, *bob);
		alex->use(2, *bob);
		alex->use(3, *bob);
		alex->use(4, *bob);
		alex->unequip(0);
		delete ice1;
		alex->use(0, *bob);
		alex->use(1, *bob);
		alex->use(2, *bob);
		alex->use(3, *bob);
		alex->unequip(6);
		alex->unequip(4);
		alex->unequip(-1);
	
		delete alex;
		delete bob;
		std::cout << "\n----------------------------------\n" << std::endl;
		return (0);
	}
}
