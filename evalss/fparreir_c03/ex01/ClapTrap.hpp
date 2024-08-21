#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
   public:
      ClapTrap();
      ClapTrap(const std::string &name);
      ClapTrap(const ClapTrap &obj);
      ~ClapTrap();
      ClapTrap& operator = (const ClapTrap &obj);

	  void	attack(const std::string &target);
	  void	takeDamage(unsigned int value);
	  void	beRepaired(unsigned int value);

	  int			getHealth() const;
	  int			getBaseHealth() const;
	  bool			canAttack() const;
	  void			printStatus() const;
	  std::string	getName() const;
	  unsigned int	getEnergy() const;
	  unsigned int	getDamage() const;

      protected:
	    std::string  name;
      	int hitpoints;
      	int base_hitpoints;
	  	unsigned int energy;
		unsigned int damage;
};