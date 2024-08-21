#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base *generate(void) {
	switch (rand() % 3)
	{
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
		default:
			print("There was an error with the generator :(");
			return (NULL);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		print("Type: A");
	else if (dynamic_cast<B*>(p))
		print("Type: B");
	else if (dynamic_cast<C*>(p))
		print("Type: C");
	else
		print("Type: unknown");
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		print("Type: A");
	} catch (std::exception &e) { ; }
	try {
		B b = dynamic_cast<B&>(p);
		print("Type: B");
	} catch (std::exception &e) { ; }
	try {
		C c = dynamic_cast<C&>(p);
		print("Type: C");
	} catch (std::exception &e) { ; }
}

int main() {
	srand(time(NULL));
	Base *test;
	test = generate();
	identify(test);
	delete(test);
	test = generate();
	identify(test);
	delete(test);
}