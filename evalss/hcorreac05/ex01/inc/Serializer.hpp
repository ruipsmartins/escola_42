#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string name;
}				Data;

class Serializer {
	private:
		
	protected:
		
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif