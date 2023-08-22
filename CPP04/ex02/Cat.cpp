/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:02:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:02:42 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Constructor called." << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor called." << std::endl;
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat copy Constructor called." << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "Cat equal operator called." << std::endl;
	if (this != &src)
	{
		delete this->brain;
		this->brain = new Brain(*src.brain);
	}
	return *this;
}


void	Cat::makeSound() const
{
	std::cout << "Nyang~ Nyang~ veryvery MewMew~~" << std::endl;
}

void Cat::setIdeas(int i, std::string idea)
{
	std::cout << "Cat [" << i << "]" << "Brain Storming!!!" << std::endl;
	brain->setIdeas(i, idea);
}

void Cat::printIdeas() const
{
	std::cout << type << "print " << std::endl;
	brain->printIdeas();
}