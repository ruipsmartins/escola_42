/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:26:34 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/24 17:44:03 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){

	Data D;

	D.name = "Horio";
	D.favChamp = "Gnar";
	D.division = 1;
	D.kda = 4.7;

	std::cout << "Pointer Value at the Start \n"
	<< "Name: " << D.name << std::endl
	<< "Fav Champ: " << D.favChamp << std::endl
	<< "Division: " << D.division << std::endl
	<< "KDA: " << D.kda << std::endl;

	Data* D_end = Serializer::deserialize(Serializer::serialize(&D));

	std::cout << "\nPointer Value at the End \n"
	<< "Name: " << D_end->name << std::endl
	<< "Fav Champ: " << D_end->favChamp << std::endl
	<< "Division: " << D_end->division << std::endl
	<< "KDA: " << D_end->kda << std::endl;

}