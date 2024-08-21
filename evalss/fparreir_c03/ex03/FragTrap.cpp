#include "FragTrap.hpp"

const int FragTrap::ATTACK_DAMAGE = 30;

FragTrap::FragTrap() : ClapTrap() {
	this->base_hitpoints = 100;
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}


FragTrap::FragTrap(const std::string &_name) : ClapTrap(_name) {
	this->base_hitpoints = 100;
	this->hitpoints = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj) {
	std::cout << "FragTrap copy constructor called" << std::endl;

	this->energy = obj.getEnergy();
	this->hitpoints = obj.getHealth();
	this->base_hitpoints = obj.getBaseHealth();
	this->damage = obj.getDamage();

}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;

	if (this != &obj)
	{
		this->energy = obj.getEnergy();
		this->damage = obj.getDamage();
		this->base_hitpoints = obj.getBaseHealth();
		this->hitpoints = obj.getHealth();
		this->name = obj.getName();
	}
	return *this;
}

void	FragTrap::highFivesGuys() {
	std::cout << "The FragTrap called " << this->getName();
	std::cout << " gives a round of high fives to the guys!" << std::endl;
}

unsigned int	FragTrap::getDamage() const {
	return this->FragTrap::damage;
}

