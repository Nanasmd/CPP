/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:58:26 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:58:28 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Constructor called." << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called." << std::endl;
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog copy Constructor called." << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog equal operator called." << std::endl;
	if (this != &src)
	{
		delete this->brain;
		this->brain = new Brain(*src.brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Wang! Wang!Kking~~ Kking~~~" << std::endl;
}

void Dog::setIdeas(int i, std::string idea)
{
	std::cout << "Dog [" << i << "]" << "Brain Storming!!!" << std::endl;
	brain->setIdeas(i, idea);
}

void Dog::printIdeas() const
{
	std::cout << type << "print " << std::endl;
	brain->printIdeas();
}