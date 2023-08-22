/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:05:17 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:05:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): name("")
{
	for (int i = 0; i < SLOTS; i++)
		this->inven[i] = NULL;
}
Character::~Character()
{
	for (int i = 0; i < SLOTS; i++)
	{
		if (inven[i])
			delete inven[i];
	}
}

Character::Character(Character const &src)
{
	this->name = src.name;
	for (int i = 0; i < SLOTS; i++)
		if(!this->inven[i])
			this->equip(src.inven[i]->clone());
}

Character::Character(std::string const _name): name(_name)
{
	for (int i = 0; i < SLOTS; i++)
		this->inven[i] = NULL;
}

Character &Character::operator=(Character const &src)
{
	this->name = src.getName();
	for (int i = 0; i < SLOTS; i++)
		if(!this->inven[i])
			this->inven[i] = src.inven[i]->clone();
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < SLOTS; i++)
			if(!this->inven[i])
			{
				this->inven[i] = m;
				return ;
			}
	}
	return ;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->inven[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && this->inven[idx])
		this->inven[idx]->use(target);
	else
		std::cout << "can't use Amateria." << std::endl;
}