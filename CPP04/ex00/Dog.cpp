/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:53:03 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:53:10 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called." << std::endl;
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog copy Constructor called." << std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog equal operator called." << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wang! Wang!Kking~~ Kking~~~" << std::endl;
}