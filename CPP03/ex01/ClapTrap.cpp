/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:39:47 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:40:04 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string newName): Name(newName), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Constructor member initallizer list called." <<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called." << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->HitPoints == 0)
	{
		std::cout << this->Name << " can't attack because dead." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->Name << " attacks " << target << "," << 
		" causing " << this->AttackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->HitPoints -= amount;
	if (this->HitPoints < 0){
		this->HitPoints = 0;
		std::cout << this->Name << " die." << std::endl;
	}
	else {
		std::cout << this->Name << " is take " << amount << " damage." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->HitPoints += amount;
	this->EnergyPoints += amount;
	std::cout << "HP and EP of " << this->Name << " have been restored by " << amount << "." << std::endl;
}

void	ClapTrap::useSkill(std::string const &target)
{
	int		SkillDamage = 20;
	if (this->EnergyPoints == 0)
	{
		std::cout << "Not enough EnergyPoints" << std::endl;
	}
	else {
		this->EnergyPoints -= 2;
		std::cout << this->Name << " uses skill on " << target << "." << std::endl;
		std::cout << "fire bolt!!!!" << std::endl;
		std::cout << "ClapTrap " << this->Name << " attacks " << target << "," << 
		" causing " << SkillDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::showState(void)
{
	std::cout << this->Name << "'s HP is " << this->HitPoints << "." << std::endl;
	std::cout << this->Name << "'s EP is " << this->EnergyPoints << "." << std::endl;
}