#pragma once

#include <ClapTrap.hpp>

class ScavTrap: public ClapTrap
{
   public:
      ScavTrap();
      ScavTrap(const std::string &name);
      ScavTrap(const ScavTrap &obj);
      ~ScavTrap();
      ScavTrap& operator = (const ScavTrap &obj);

	  void attack(const std::string &target);
	  void guardGate();

	  bool getGuardStatus() const;

	private:
		bool isGuarding;
};