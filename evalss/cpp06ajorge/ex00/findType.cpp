/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:46:20 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/11 13:48:37 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


bool isInteger(const std::string &value){
	char *end;
	std::strtol(value.c_str(), &end, 10);
	return *end == '\0'; //Se chegou ao final da string quer dizer que é um sucesso
}

bool isDouble(const std::string &value){
	char *end;
	if(value.find(".") == std::string::npos)
		return false;
	std::string value2;
	if(value[value.length() - 1] == 'f')
		value2 = value.substr(0, value.length() - 1);
	std::strtof(value2.c_str(), &end);
	return *end == '\0';
}

bool isChar(const std::string &value){
	return(!(value[0] == '\0') && value.length() == 1 && !std::isdigit(value[0]));
}

int findType(const std::string &value){
	
	//Special Cases
	if(value.empty())
		return 5;
	else if(!value.compare("-inff") || !value.compare("+inff") || !value.compare("+inf") || !value.compare("-inf") || !value.compare("nan") || !value.compare("nanf"))
		return 0;
	//Integer
	else if(isInteger(value))
		return 1;
	//float
	else if(isDouble(value) && value[value.length() - 1] == 'f')
		return 2;
	//Double
	else if(isDouble(value))
		return 3;
	else if(isChar(value))
		return 4;
	else
		return 5;
}

void specialCases(const std::string &value){
	std::cout << "char: impossible" << std::endl
	<< "int: impossible" << std::endl;
	if(!value.compare("nan") || !value.compare("nanf")){
		std::cout << "float: nanf" << std::endl
		<< "double: nan" << std::endl;
	}
	else if(!value.compare("+inf") || !value.compare("+inff")){
		std::cout << "float: +inff" << std::endl
		<< "double: +inf" << std::endl;
	}
	else if(!value.compare("-inf") || !value.compare("-inff")){
		std::cout << "float: -inff" << std::endl
		<< "double: -inf" << std::endl;
	}
}

void printInt(const std::string &value){
	int n = std::atoi(value.c_str());
	
	if(n >= 0 && n <= 127)
	{
		if(std::isprint(n))
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << n
	<< std::fixed << std::setprecision(1) << std::endl 
	<< "float: " << static_cast<float>(n) << "f" << std::endl
	<< "double: " << static_cast<double>(n) << std::endl;
}

void printFloat(const std::string &value){
	float n = std::atof(value.c_str());
	
	if(n >= 0 && n <= 127)
	{
		if(std::isprint(n))
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(n)
	<< std::fixed << std::setprecision(1) << std::endl
	<< "float: " << n << "f" << std::endl
	<< "double: " << static_cast<double>(n) << std::endl;
}

void printDouble(const std::string &value){
	double n = std::atof(value.c_str());
	
	if(n >= 0 && n <= 127)
	{
		if(std::isprint(n))
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(n)
	<< std::fixed << std::setprecision(1) << std::endl 
	<< "float: " << static_cast<float>(n) << "f" << std::endl
	<< "double: " << static_cast<double>(n) << std::endl;
}

void printChar(char c){
	std::cout << "char: " << c << std::endl
	<< "int: " << static_cast<int>(c)
	<< std::fixed << std::setprecision(1) << std::endl 
	<< "float: " << static_cast<float>(c) << "f" << std::endl
	<< "double: " << static_cast<double>(c) << std::endl;
}

