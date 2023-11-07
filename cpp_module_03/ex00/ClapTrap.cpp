/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:40:40 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/31 15:31:12 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// --------------------------- CONSTRUCTEURS ----------------------------------

// Constructeur par défaut
ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap constructeur par défaut appelé" << std::endl;
	this->_name = "default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Constructeur avec paramètre pour initialiser le nom
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructeur avec paramètre appelé" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Constructeur de copie
ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap constructeur de copie appelé" << std::endl;
	*this = copy;
}

// Destructeur
ClapTrap::~ClapTrap(void)
{
	// Affichage d'un message pour indiquer que le destructeur est appelé
	std::cout << "ClapTrap destructeur appelé" << std::endl;
}

// --------------------------- OPERATEURS ----------------------------------

// Surcharge de l'opérateur d'affectation
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

// --------------------------- FONCTIONS D'ACCÈS (GETTERS) ----------------------------------

// Fonctions retournant les valeurs des attributs correspondants.
std::string	ClapTrap::getName(void) const {return (this->_name);}
int			ClapTrap::getHitPoints(void) const {return (this->_hitPoints);}
int			ClapTrap::getEnergyPoints(void) const {return (this->_energyPoints);}
int			ClapTrap::getAttackDamage(void) const {return (this->_attackDamage);}

// --------------------------- FONCTIONS MEMBRES ----------------------------------

// Vérifie si le jeu est terminé (énergie ou points de vie épuisés)
bool	ClapTrap::isGameOver(void)
{
	if (!this->_energyPoints || !this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << BOLD_RED << " est hors service!" << RESET << std::endl;
		return (true);
	}
	return (false);
}

// Fonction pour attaquer une cible
void	ClapTrap::attack(const std::string& target)
{
	if (this->isGameOver())
		return ;
	std::cout << "ClapTrap " << this->_name << PURPLE << " attaque " << RESET << target;
	std::cout << ", causant " << PURPLE << this->_attackDamage << " points de dégâts!" << RESET << std::endl;
	this->_energyPoints--;
}

// Fonction pour subir des dégâts
void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " perd " << BOLD_RED << amount << " HP!" << RESET << std::endl;
}

// Fonction pour être réparé
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isGameOver())
		return ;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " est réparé de " << GREEN << amount << " HP!" << RESET << std::endl;
	this->_energyPoints--;
}

// Surcharge de l'opérateur d'insertion pour afficher l'état du ClapTrap
std::ostream	&operator<<(std::ostream &out, ClapTrap const &trap)
{
	out << "ClapTrap " << trap.getName() << " a " << trap.getHitPoints() << " HP et ";
	out << trap.getEnergyPoints() << " d'énergie.";
	return (out);
}