/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:54:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:54:36 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->WrongAnimal::type = "WrongCat";
	std::cout << "WrongCat Constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << "WrongCat copy Constructor called." << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	std::cout << "WrongCat equal operator called." << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat Nyang~ Nyang~" << std::endl;
}