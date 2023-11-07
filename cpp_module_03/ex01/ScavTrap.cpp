/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:15:54 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/31 15:34:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// --------------------------- CONSTRUCTEURS ----------------------------------

// Constructeur par défaut
ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// Constructeur avec paramètre pour initialiser le nom
ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor with parameter called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// Constructeur de copie
ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Destructeur
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

// --------------------------- OPERATEURS ----------------------------------

// Surcharge de l'opérateur d'affectation
ScavTrap	&ScavTrap::operator = (ScavTrap const &copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	return (*this);
}

// --------------------------- FONCTIONS MEMBRES ----------------------------------

// Attaque une cible de manière spécifique au ScavTrap. (surchargée)
void	ScavTrap::attack(std::string const &target)
{
	if (!this->getHitPoints() || !this->getEnergyPoints())
	{
		std::cout << "ScavTrap " << this->_name << BOLD_RED << " is out of action!" << RESET << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << PINK << " bombs " << RESET << target;
	std::cout << ", causing " << PINK << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->_energyPoints--;
}

// Active le mode gardien pour le ScavTrap.
void	ScavTrap::guardGate(void)
{
	std::cout << YELLOW << "ScavTrap " << this->_name << " has enterred in Gate keeper mode" << RESET << std::endl;
}
