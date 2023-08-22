/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:46:46 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:46:57 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(std::string newName):ClapTrap(newName), FragTrap(newName), ScavTrap(newName)
{
	std::cout << "DiamondTrap Default value Constructor called" << std::endl;
	this->Name = newName;
	ClapTrap::Name = this->Name + "_clap_name";
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called." << std::endl;
}

void  DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void  DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap Name: " << this->Name << std::endl;
	std::cout << "ClapTrap Name: " << ClapTrap::Name << std::endl;
}