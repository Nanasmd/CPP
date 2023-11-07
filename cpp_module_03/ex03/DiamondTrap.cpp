/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:48:53 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/31 16:59:20 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// --------------------------- CONSTRUCTEURS ----------------------------------

// Constructeur par défaut
DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hitPoints = FragTrap::initHit;
	this->_energyPoints = ScavTrap::initEnergy;
	this->_attackDamage = FragTrap::initDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

// Constructeur avec paramètre pour initialiser le nom
DiamondTrap::DiamondTrap(std::string const diamondName) : ClapTrap(diamondName), ScavTrap(diamondName), FragTrap(diamondName)
{
	std::cout << "DiamondTrap constructor with parameter called" << std::endl;
	this->_name = diamondName;
	this->_hitPoints = FragTrap::initHit;
	this->_energyPoints = ScavTrap::initEnergy;
	this->_attackDamage = FragTrap::initDamage;
	this->ClapTrap::_name = this->_name + "_clap_name";
}

// Constructeur de copie
DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = copy._name;
}

// Destructeur
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

// --------------------------- OPERATEURS ----------------------------------

// Surcharge de l'opérateur d'affectation
DiamondTrap	&DiamondTrap::operator = (DiamondTrap const &copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	this->ClapTrap::_name = copy.ClapTrap::_name;
	return (*this);
}

// --------------------------- FONCTIONS MEMBRES ----------------------------------

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name;
	std::cout << " is also known as " << this->ClapTrap::_name << std::endl;
}