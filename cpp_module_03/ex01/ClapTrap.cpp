/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:15:33 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/31 15:32:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// --------------------------- CONSTRUCTEURS ----------------------------------

// Constructeur par défaut
ClapTrap::ClapTrap(void)
{
	// Affichage d'un message pour indiquer que le constructeur par défaut est appelé
	std::cout << "ClapTrap default constructor called" << std::endl;
	// Initialisation des attributs avec des valeurs par défaut	this->_name = "default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Constructeur avec paramètre pour initialiser le nom
ClapTrap::ClapTrap(std::string name)
{
	// Affichage d'un message pour indiquer que le constructeur avec paramètre est appelé
	std::cout << "ClapTrap constructor with parameter called" << std::endl;
	// Initialisation des attributs avec des valeurs spécifiées
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

// Constructeur de copie
ClapTrap::ClapTrap(ClapTrap const &copy)
{
	// Affichage d'un message pour indiquer que le constructeur de copie est appelé
	std::cout << "ClapTrap copy constructor called" << std::endl;
	// Utilisation de l'opérateur d'affectation pour copier les attributs
	*this = copy;
}

// Destructeur
ClapTrap::~ClapTrap(void)
{
	// Affichage d'un message pour indiquer que le destructeur est appelé
	std::cout << "ClapTrap destructor called" << std::endl;
}

// --------------------------- OPERATEURS ----------------------------------

// Surcharge de l'opérateur d'affectation
ClapTrap	&ClapTrap::operator = (ClapTrap const &copy)
{
	// Vérification de l'auto-affectation
	if (this == &copy)
		return (*this);
	// Copie des attributs
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	// Retour de l'instance actuelle
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
		std::cout << "ClapTrap " << this->_name << BOLD_RED << " is out of action!" << RESET << std::endl;
		return (true);
	}
	return (false);
}

// Fonction pour attaquer une cible
void	ClapTrap::attack(const std::string& target)
{
	if (this->isGameOver())
		return ;
	std::cout << "ClapTrap " << this->_name << PURPLE << " attacks " << RESET << target;
	std::cout << ", causing " << PURPLE << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->_energyPoints--;
}

// Fonction pour subir des dégâts
void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " loose " << BOLD_RED << amount << " HP!" << RESET << std::endl;
}

// Fonction pour être réparé
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isGameOver())
		return ;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired with " << GREEN << amount << " HP!" << RESET << std::endl;
	this->_energyPoints--;
}

// Surcharge de l'opérateur d'insertion pour afficher l'état du ClapTrap
std::ostream	&operator<<(std::ostream &out, ClapTrap const &trap)
{
	out << "ClapTrap " << trap.getName() << " has " << trap.getHitPoints() << " HP and ";
	out << trap.getEnergyPoints() << " battery life.";
	return (out);
}

