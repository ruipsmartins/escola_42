#include <DiamondTrap.hpp>

int main() {
	DiamondTrap filipe("Filipe");
	filipe.printStatus();
	filipe.whoAmI();
	std::cout << "-----------------------------------" << std::endl;

	DiamondTrap test = filipe;
	test.guardGate();
	test.attack("binary");
	test.highFivesGuys();
	test.printStatus();
	test.whoAmI();
	std::cout << "-----------------------------------" << std::endl;

	DiamondTrap empty;

	empty.whoAmI();
	empty.printStatus();
	std::cout << "-----------------------------------" << std::endl;
	empty = test;
	empty.whoAmI();
	empty.printStatus();
	std::cout << "-----------------------------------" << std::endl;

}