/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:19:37 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/24 17:39:44 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout << "Serializer Default Constructor" << std::endl;
}

Serializer::~Serializer(){
	std::cout << "Serializer Destructor" << std::endl;
}

Serializer::Serializer(const Serializer &other){
	std::cout << "Serializer Copy Constructor" << std::endl;
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &copy){
	std::cout << "Serializer Copy Operator" << std::endl;
	if(this != &copy)
		*this = copy;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}