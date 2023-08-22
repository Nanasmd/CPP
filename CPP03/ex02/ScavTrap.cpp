/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:44:43 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:44:51 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string newName):ClapTrap(newName)
{
	std::cout << "ScavTrap Default value Constructor called" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScaveTrap Destructor called." << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->Name << " have entered in Gate keeper mode." << std::endl;
}