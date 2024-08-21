#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->base_hitpoints = 100;
	this->hitpoints = 100;
	this->energy = 50;
	this->damage = 20;
	this->isGuarding = false;
	std::cout << "ScavTrap Constructor called" << std::endl;
}


ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	this->base_hitpoints = 100;
	this->hitpoints = 100;
	this->energy = 50;
	this->damage = 20;
	this->isGuarding = false;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj) {
	std::cout << "ScavTrap copy constructor called" << std::endl;

	this->energy = obj.getEnergy();
	this->hitpoints = obj.getHealth();
	this->base_hitpoints = obj.getBaseHealth();
	this->damage = obj.getDamage();
	this->isGuarding = false;

}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;

	if (this != &obj)
	{
		this->energy = obj.getEnergy();
		this->damage = obj.getDamage();
		this->base_hitpoints = obj.getBaseHealth();
		this->hitpoints = obj.getHealth();
		this->name = obj.getName();
		this->isGuarding = obj.getGuardStatus();
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target) {
	this->printStatus();
	if (this->canAttack())
	{
		std::cout << "ScavTrap " << this->getName() <<  " attacks " << target;
		std::cout << ", causing " << this->getDamage() << " points of damage!" << std::endl;
		this->energy--;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " tried to attack ";
		std::cout << target << " but he doesn't have anymore energy/hitpoints left!" << std::endl;
	}
}

bool	ScavTrap::getGuardStatus() const { return this->isGuarding; }

void	ScavTrap::guardGate() {
	if (!this->getGuardStatus())
	{
		std::cout << "The ScavTrap named " << this->getName();
		std::cout << " is now in Guard mode!" << std::endl;
		this->isGuarding = !this->isGuarding;
	}
	else
	{
		std::cout << "The ScavTrap named " << this->getName();
		std::cout << " is no longer in Guard mode!" << std::endl;
		this->isGuarding = !this->isGuarding;
	}
}