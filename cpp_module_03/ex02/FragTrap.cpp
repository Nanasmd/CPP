/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:12:26 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/31 15:53:28 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// --------------------------- CONSTRUCTEURS ----------------------------------

// Constructeur par défaut
FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Constructeur avec paramètre pour initialiser le nom
FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor with parameter called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Constructeur de copie
FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// Destructeur
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

// --------------------------- OPERATEURS ----------------------------------

// Surcharge de l'opérateur d'affectation
FragTrap	&FragTrap::operator = (FragTrap const &copy)
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

// Vérifie si le jeu est terminé (énergie ou points de vie épuisés)
void	FragTrap::attack(std::string const &target)
{
	if (!this->_energyPoints || !this->_hitPoints)
	{
		std::cout << "FragTrap " << this->_name << BOLD_RED << " is out of action!" << RESET << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << V_CYAN << " bombs " << RESET << target;
	std::cout << ", causing " << V_CYAN << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->_energyPoints--;
}

// Fonction pour high five
void	FragTrap::highFivesGuys(void)
{
	std::cout << V_CYAN << "FragTrap " << this->_name << " high fives everyone!" << RESET << std::endl;
}
