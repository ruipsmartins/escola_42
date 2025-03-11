/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:45:03 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/11 11:46:47 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
	std::cout << "Base Destructor" << std::endl;
}

Base* generate(void){
	std::srand(std::time(0));
	int chance = std::rand() % 3;
	//std::cout << "Chance = " << chance << std::endl;
	switch(chance){
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			std::cout << "Unknown" << std::endl;
	}
	return NULL;
}

void identify(Base* p){
	if(dynamic_cast<A*>(p))
		std::cout << " 'A' Type Object" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << " 'B' Type Object" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << " 'C' Type Object" << std::endl;
}

void identify(Base& p){
	//Tem de se usar o try and catch devido a que o dynamic cast dá throw a uma exception quando o cast nao é valido
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << " 'A' Type Object" << std::endl;
		return ;
	} catch (std::exception& e) {}

	try{
		(void)dynamic_cast<B&>(p);
		std::cout << " 'B' Type Object" << std::endl;
		return ;
	} catch (std::exception& e) {}

	try{
		(void)dynamic_cast<C&>(p);
		std::cout << " 'C' Type Object" << std::endl;
		return ;
	} catch (std::exception& e) {}
}