/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:01:17 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:01:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Unknown")
{
	std::cout << "Default value Constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy Constructor called." << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &src)
{
	std::cout << "Animal equal operator called." << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}