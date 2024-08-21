#include <ClapTrap.hpp>

int main()
{
	ClapTrap test("attacks_object");

	for(int i = 0; i < 15; i++)
		test.attack("bananas");

	ClapTrap test1("damage_object");

	for(int i = 0; i < 11; i++)
		test1.takeDamage(i + i);

	for(int i = 0; i < 11; i++)
	{
		test1.beRepaired(i + i);

	}
}