#pragma once

#include <iostream>
#include <cstdlib>
#include <exception>

#define print(x) std::cout << x << std::endl

class A;
class B;
class C;

class Base {
	public:
		virtual ~Base();
};