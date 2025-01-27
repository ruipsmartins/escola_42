#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int	main( void ) {
	{ // Invalid materia index on player
		std::cout << INVERT << "use materia[-1]:" << RESET << std::endl;
		Character	wanda("Wanda");
		Character	vision("Vision");

		wanda.use(-1, vision);
	}
	{ // Empty materia index on player
		std::cout << std::endl << INVERT << "use empty materia:" << RESET << std::endl;
		Character	wanda("Wanda");
		Character	vision("Vision");

		wanda.use(0, vision);
	}
	{ // Create/equip NULL materia
		std::cout << std::endl << INVERT << "Create/equip NULL materia:" << RESET << std::endl;
		MateriaSource mat;
		Character	wanda("Wanda");

		wanda.equip(mat.createMateria("fire"));
	}
	{ // Full backpack
		std::cout << std::endl << INVERT << "Full backpack:" << RESET << std::endl;
		MateriaSource	mat;
		Character		wanda("Wanda");
		mat.learnMateria(new Ice());
		for (int i = 0; i < 4; i++) {
			wanda.equip(mat.createMateria("ice"));
		}
		wanda.equip(mat.createMateria("ice"));
	}
	{ // Character deep copy
		std::cout << std::endl << INVERT << "Character deep copy:" << RESET << std::endl;
		MateriaSource	mat;
		Character		wanda("Wanda");
		Character		vision("Vision");

		mat.learnMateria(new Ice());
		for (int i = 0; i < 4; i++)
			wanda.equip(mat.createMateria("ice"));
		{
			std::cout << YELLOW << "creating copy characters" << RESET << std::endl;
			Character	fake_wanda(wanda);
			Character	faker_wanda = wanda;
			std::cout << YELLOW << "killing copy characters" << RESET << std::endl;
		}
		wanda.use(0, vision);
	}
	{ // Materia deep copy
		std::cout << std::endl << INVERT << "Materia deep copy:" << RESET << std::endl;
		MateriaSource	mat;
		Ice *ice = new Ice();
		{
			std::cout << YELLOW << "creating copy materias" << RESET << std::endl;
			Ice	*ice1 = ice;
			Ice	*ice2(ice);
			ice1->getType();
			ice2->getType();
			std::cout << YELLOW << "Copy materias: " << &ice1 << RESET << std::endl;\
			std::cout << YELLOW << "copy materias: " << &ice2 << RESET << std::endl;
		}
		mat.learnMateria(ice);
	}
	{ // MateriaSource deep copy
		std::cout << std::endl << INVERT << "MateriaSource deep copy:" << RESET << std::endl;
		MateriaSource	mat;
		Character		wanda("Wanda");

		mat.learnMateria(new Ice());
		{
			std::cout << YELLOW << "creating copy MateriaSources" << RESET << std::endl;
			MateriaSource	mat1 = mat;
			MateriaSource	mat2(mat);
			std::cout << YELLOW << "deleting copy MateriaSources" << RESET << std::endl;
		}
		wanda.equip(mat.createMateria("ice"));
	}
	{ // Materia does not exist
		std::cout << std::endl << INVERT << "Materia does not exist:" << RESET << std::endl;
		MateriaSource	mat;
		Character	wanda("Wanda");

		mat.learnMateria(new Ice());
		wanda.equip(mat.createMateria("aku aku"));
	}
	{ // MateriaSource is full
		std::cout << std::endl << INVERT << "MateriaSource is full" << RESET << std::endl;
		MateriaSource	mat;

		mat.learnMateria(new Cure());
		mat.learnMateria(new Ice());
		mat.learnMateria(new Ice());
		mat.learnMateria(new Cure());
		mat.learnMateria(new Ice());
	}
	{ // Unequip leaks
		std::cout << std::endl << INVERT << "Unequip:" << RESET << std::endl;
		MateriaSource	mat;
		Character		wanda("Wanda");
		Character		vision("Vision");

		mat.learnMateria(new Ice());
		mat.learnMateria(new Cure());
		for (int i = 0; i < SIZE; i++)
		{
			if (i % 2 == 0)
				wanda.equip(mat.createMateria("ice"));
			else 
				wanda.equip(mat.createMateria("cure"));
		}
		wanda.unequip(0);
		std::cout << BOLD << "Empty: " << RESET;
		wanda.use(0, vision);
		std::cout << BOLD << "Other: " << RESET;
		wanda.use(1, vision);
		wanda.equip(mat.createMateria("ice"));
		wanda.use(0, vision);
	}
}
