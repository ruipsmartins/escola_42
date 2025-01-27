#include "easyfind.hpp"

int main()
{
	{
	std::cout << "----- DEQUE -----" << std::endl;
	std::deque<int> d;
	for (int i=1; i<=5; i++) 
		d.push_back(i);
	std::cout << "find(1) :" << *easyfind(d, 1) << std::endl;
	std::deque<int>::iterator i = easyfind(d, 5);
	if (i == d.end())
		std::cout << "find(404) : Not found"<< std::endl;
	std::cout << std::endl;
	}

	{
	std::cout << "----- VECTOR -----" << std::endl;
    std::vector<int> v;
	for (int i=0; i<=5; i++) 
		v.push_back(i);
	std::cout << "find(0) :" << *easyfind(v, 0) << std::endl;
	std::vector<int>::iterator i = easyfind(v, 404);
	if (i == v.end())
		std::cout << "find(404) : Not found"<< std::endl;
	std::cout << std::endl;
	}

	{
	std::cout << "----- LIST -----" << std::endl;
    int myints[] = {75,23,65,42,13};
  	std::list<int> l (myints,myints+5);
	std::cout << "find(65) :" << *easyfind(l, 65) << std::endl;
	std::list<int>::iterator i = easyfind(l, 404);
	if (i == l.end())
		std::cout << "find(404) : Not found"<< std::endl;
	std::cout << std::endl;
	}

}