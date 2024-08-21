#include "../inc/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Default constructor called" << std::endl;
}

Serializer::~Serializer() {
	std::cout << "Default destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& copy) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = copy;
}

Serializer& Serializer::operator=(const Serializer& copy) {
	std::cout << "Default assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}