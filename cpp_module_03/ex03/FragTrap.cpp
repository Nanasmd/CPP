/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:49:03 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/16 19:46:10 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// --------------------------- CONSTRUCTORS ----------------------------------

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = this->initHit;
	this->_energyPoints = this->initEnergy;
	this->_attackDamage = this->initDamage;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor with parameter called" << std::endl;
	this->_hitPoints = this->initHit;
	this->_energyPoints = this->initEnergy;
	this->_attackDamage = this->initDamage;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

// --------------------------- OPERATORS ----------------------------------

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

// --------------------------- MEMBER FUNCTIONS ----------------------------------

void	FragTrap::attack(std::string const &target)
{
	if (!this->_energyPoints || !this->_hitPoints)
	{
		std::cout << "FragTrap " << this->_name << " is out of action!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " bombs " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " high fives everyone!" << std::endl;
}