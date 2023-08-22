/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:04:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:04:44 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): type(""){}

AMateria::~AMateria(){}

AMateria::AMateria(std::string const & type): type(type){}

std::string const &AMateria::getType() const
{
	return this->type;	
}

void AMateria::use(ICharacter& target){
	(void) target;
}

AMateria &AMateria::operator=(AMateria const &src)
{
	this->type = src.type;
	return *this;
}

AMateria::AMateria(AMateria const &src)
{
	this->type = src.type;
}