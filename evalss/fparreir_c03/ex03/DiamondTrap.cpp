#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap() {
	this->name = "John Doe";
	this->ClapTrap::name = "John Doe_clap_name";
	this->hitpoints = FragTrap::hitpoints;
	this->base_hitpoints = FragTrap::base_hitpoints;
	this->damage = FragTrap::ATTACK_DAMAGE;
	this->energy = this->ScavTrap::energy;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &_name)
 :	ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name){
	this->name = _name;
	this->hitpoints = FragTrap::hitpoints;
	this->base_hitpoints = FragTrap::base_hitpoints;
	this->damage = FragTrap::ATTACK_DAMAGE;
	this->energy = this->ScavTrap::energy;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(obj.name), FragTrap(obj.name), ScavTrap(obj.name) {
	*this = obj;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->ClapTrap::name = obj.getName();
		this->hitpoints = obj.hitpoints;
		this->base_hitpoints = obj.base_hitpoints;
		this->energy = obj.energy;
		this->damage = obj.damage;
	}
	return *this;
}


void	DiamondTrap::whoAmI() {
	std::cout << "My ClapTrap name is: " << ClapTrap::name << std::endl;
	std::cout << "My DiamondTrap name is: " << this->name << std::endl;
}

unsigned int DiamondTrap::getDamage() const {
	return this->FragTrap::damage;
}