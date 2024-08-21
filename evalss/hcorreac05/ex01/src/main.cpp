#include "../inc/Serializer.hpp"

int main() {
	Data *data = new Data;
	uintptr_t ptr;
	Data *data2;

	data->name = "Alberto";
	ptr = Serializer::serialize(data);
	data2 = Serializer::deserialize(ptr);
	std::cout << "Original: " << data->name << std::endl;
	std::cout << "Serialized: " << ptr << std::endl;
	std::cout << "Deserialized: " << data2->name << std::endl;
	std::cout << "Address of original: " << data << std::endl << "Address of deserialized: " << data2 << std::endl;
	delete(data);
}