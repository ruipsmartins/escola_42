#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("John Doe"), hitpoints(10), base_hitpoints(10), energy(10), damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
		: name(name), hitpoints(10), base_hitpoints(10),energy(10), damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
	: name(obj.name), hitpoints(obj.hitpoints), base_hitpoints(obj.base_hitpoints),
		energy(obj.energy), damage(obj.damage)  {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;

	if (this != &obj)
		this->name = obj.name;

	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->canAttack())
	{
		std::cout << "ClapTrap " << this->name <<  " attacks " << target;
		std::cout << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energy--;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " tried to attack ";
		std::cout << target << " but he doesn't have anymore energy/hitpoints left!" << std::endl;
	}
}

void	ClapTrap::beRepaired (unsigned int value) {
	if (this->energy > 0)
	{
		if (this->hitpoints + value <= (unsigned int)this->base_hitpoints)
		{
			this->hitpoints += (int)value;
			std::cout << "ClapTrap " << this->name;
			std::cout << " repairs itself and gains " << value;
			std::cout << " of hitpoints! He now has " << this->hitpoints;
			std::cout << " life points" << std::endl;
			this->energy--;
		}
		else
		{
			std::cout << "ClapTrap " << this->name;
			std::cout << " cannot have more than ";
			std::cout << this->base_hitpoints << " hitpoints.";
			std::cout << " Current hitpoints: " << this->hitpoints;
			std::cout << " tried to give him " << value << std::endl;

		}
	}
	else
	{
		std::cout << "ClapTrap " << this->name;
		std::cout << " tried to heal himself but he doesn't have anymore energy left!" << std::endl;
	}
}

void	ClapTrap::takeDamage (unsigned int value) {
	if (this->hitpoints > 0)
	{
		this->hitpoints -= (int)value;
		if (this->hitpoints < 0)
			this->hitpoints = 0;
		std::cout << "ClapTrap " << this->name <<  " takes " << value << " of damage! He now has " << this->hitpoints << " life points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " doesn't have any hitpoints left!" << std::endl;
}

std::string	ClapTrap::getName() const { return this->name; }

int	ClapTrap::getHealth() const { return this->hitpoints; }

int	ClapTrap::getBaseHealth() const { return this->base_hitpoints; }

unsigned int ClapTrap::getEnergy() const { return this->energy; }

unsigned int ClapTrap::getDamage() const { return this->damage; }

bool ClapTrap::canAttack() const { return this->hitpoints > 0 && this->energy > 0; }

void ClapTrap::printStatus() const {
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Hitpoints: " << this->getHealth() << std::endl;
	std::cout << "Base Hitpoints: " << this->getBaseHealth() << std::endl;
	std::cout << "Current energy: " << this->getEnergy() << std::endl;
	std::cout << "Damage: " << this->getDamage() << std::endl;
	std::string status = this->canAttack() ? "true" : "false";
	std::cout << "Can Attack: " << status << std::endl;
}