#pragma once

#include <ClapTrap.hpp>

class FragTrap: public ClapTrap
{
   public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &obj);
	~FragTrap();
	FragTrap& operator = (const FragTrap &obj);

	void highFivesGuys();
};