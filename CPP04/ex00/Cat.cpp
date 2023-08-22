/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:52:35 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:52:36 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called." << std::endl;
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat copy Constructor called." << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "Cat equal operator called." << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Nyang~ Nyang~ veryvery MewMew~~" << std::endl;
}