/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:16:22 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/25 20:02:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// --------------------------- CONSTRUCTORS ----------------------------------

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor with parameter called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

// --------------------------- OPERATORS ----------------------------------

ClapTrap	&ClapTrap::operator = (ClapTrap const &copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	return (*this);
}

// --------------------------- GET FUNCTIONS ----------------------------------

std::string	ClapTrap::getName(void) const {return (this->_name);}
int			ClapTrap::getHitPoints(void) const {return (this->_hitPoints);}
int			ClapTrap::getEnergyPoints(void) const {return (this->_energyPoints);}
int			ClapTrap::getAttackDamage(void) const {return (this->_attackDamage);}

// --------------------------- MEMBER FUNCTIONS ----------------------------------

bool	ClapTrap::isGameOver(void)
{
	if (!this->_energyPoints || !this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << BOLD_RED << " is out of action!" << RESET << std::endl;
		return (true);
	}
	return (false);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->isGameOver())
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " loose " << amount << " HP!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isGameOver())
		return ;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired with " << amount << " HP!" << std::endl;
	this->_energyPoints--;
}

std::ostream	&operator<<(std::ostream &out, ClapTrap const &trap)
{
	out << "ClapTrap " << trap.getName() << " has " << trap.getHitPoints() << " HP and ";
	out << trap.getEnergyPoints() << " energy points.";
	return (out);
}
