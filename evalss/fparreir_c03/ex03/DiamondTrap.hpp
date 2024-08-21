#pragma once

#include <ScavTrap.hpp>
#include <FragTrap.hpp>

class DiamondTrap: virtual public FragTrap, virtual public ScavTrap
{
   public:
      DiamondTrap();
      DiamondTrap(const std::string &name);
      DiamondTrap(const DiamondTrap &obj);
      ~DiamondTrap();
      DiamondTrap& operator = (const DiamondTrap &obj);

	  using ScavTrap::attack;
	  void	whoAmI();
	  unsigned int getDamage() const;

	private:
		std::string name;

};