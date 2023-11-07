/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:49:36 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:49:37 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	this->storageCount = 0;
	memset(this->storage, 0, sizeof(this->storage));
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < this->storageCount; i++)
		delete this->storage[i];
}

// Operators

MateriaSource &MateriaSource::operator=(MateriaSource const & src)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < this->storageCount; i++)
		delete this->storage[i];
	this->storageCount = src.storageCount;
	memcpy(this->storage, src.storage, sizeof(this->storage));
	return (*this);
}

// Member Functions

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->storageCount < 4)
	{
		std::cout << m->getType() << " learned" << std::endl;
		this->storage[this->storageCount++] = m;
	}
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->storageCount; i++)
	{
		if (this->storage[i]->getType() == type)
		{
			std::cout << type << " created" << std::endl;
			return (this->storage[i]->clone());
		}
	}
	std::cout << type << " not found" << std::endl;
	return (NULL);
}
