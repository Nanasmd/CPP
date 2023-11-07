/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:23:27 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:23:28 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	this->name = "default";
	this->inventoryCount = 0;
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
		this->unequiped[i] = NULL;
	}
}

Character::Character(std::string const & name)
{
	std::cout << "Character constructor with parameter called" << std::endl;
	this->name = name;
	this->inventoryCount = 0;
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = NULL;
		this->unequiped[i] = NULL;
	}
}

Character::Character(Character const & src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (this->unequiped[i])
			delete this->unequiped[i];
	}
}

// Operators

Character & Character::operator = (Character const & src)
{
	std::cout << "Character operator = called" << std::endl;
	if (this == &src)
		return (*this);
	this->name = src.name;
	this->inventoryCount = src.inventoryCount;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (this->unequiped[i])
			delete this->unequiped[i];
		this->inventory[i] = src.inventory[i];
		this->unequiped[i] = src.unequiped[i];
	}
	return (*this);
}

// Getters

std::string const & Character::getName() const {return (this->name);}

// Member Functions

void	Character::equip(AMateria* m)
{
	if (this->inventoryCount > 3)
	{
		std::cout << this->name << " has no space to equip this " << m->getType() << std::endl;
		if (m != NULL)
			delete m;
		return ;
	}
	std::cout << this->name << " equiped " << m->getType() << std::endl;
	this->inventory[this->inventoryCount++] = m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->inventory[idx] == NULL || this->unequiped[idx] != NULL)
	{
		std::cout << this->name << " has nothing to unequip" << std::endl;
		return ;
	}
	std::cout << this->name << " unequiped " << this->inventory[idx]->getType() << std::endl;
	this->unequiped[idx] = this->inventory[idx];
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
	{
		std::cout << this->name << " has nothing to use" << std::endl;	
		return ;
	}
	this->inventory[idx]->use(target);
}
