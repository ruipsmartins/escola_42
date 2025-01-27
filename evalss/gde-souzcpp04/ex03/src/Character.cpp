#include "../includes/Character.hpp"

Character::Character(std::string const & name) : ICharacter()
{
	this->_name = name;
	for (int i = 0; i < SIZE; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < SIZE * 2; i++)
		this->_dump[i] = NULL;
    //std::cout << this->_name << " Character was created.\n";
}

Character::Character() : ICharacter()
{
    this->_name= "default";
	for (int i = 0; i < SIZE; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < SIZE * 2; i++)
		this->_dump[i] = NULL;
    //std::cout << "Default Character was created.\n";
}

Character::Character(Character const &src) : ICharacter(src)
{
	this->_name = src._name;
	for (int i = 0; i < SIZE; i++)
	{
		this->_inventory[i] = NULL;
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
	}
	for (int i = 0; i < SIZE * 2; i++)
		this->_dump[i] = NULL;
	//std::cout << "Character copy constructor called.\n";
}

Character &Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < SIZE; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
		}
		for (int i = 0; i < SIZE * 2; i++)
		{
			if (this->_dump[i] != NULL)
				delete this->_dump[i];	
			this->_dump[i] = NULL;
		}
	}
	//std::cout << "Character copy assignment operator called.\n";
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < SIZE * 2; i++)
	{
		if (i < SIZE && this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (this->_dump[i] != NULL)
			delete this->_dump[i];
	}
    //std::cout << this->_name << " Character was destroyed.\n";
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < SIZE; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << m->getType() << " was added to " << this->_name << "'s inventory.\n";
			return ;
		}
	}
	delete m;
	std::cout << "Error: Failed to equip. " << this->getName() << "'s inventory is already full.\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < SIZE && this->_inventory[idx] != NULL)
	{
		for (int i = 0; i < SIZE * 2; i++)
		{
			if (this->_dump[i] == NULL)
			{
				this->_dump[i] = this->_inventory[idx];
				break ;
			}
		}
		this->_inventory[idx] = NULL;
		std::cout << "Index " << idx << " of " << this->_name << "'s inventory was unequiped.\n";
	}
	std::cout << "Error: Failed to unequip " << this->_name << std::endl;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= SIZE)
		std::cout << "Error: The given index is not valid.\n";
	else if (this->_inventory[idx] == NULL)
		std::cout << "Error: The given index has NULL value.\n";
	else if ((idx < SIZE))
		this->_inventory[idx]->use(target);
	// else
	// 	std::cout << "Error: It is not possible to use any AMateria. " << this->_name << "'s inventory is empty.\n";
}
