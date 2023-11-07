/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:40:34 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/31 15:23:04 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define RESET		"\e[0m"
#define BOLD 		"\033[1m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define BOLD_RED	"\e[1;31m"
#define BLUE		"\e[0;34m"
#define V_CYAN		"\e[0;38;5;44m"
#define GREEN       "\e[0;32m"
#define YELLOW      "\e[0;33m"

# include <iostream>
# include <cstdlib>

class ClapTrap {
private:
    // Attributs privés pour stocker le nom, les points de vie, les points d'énergie et les dégâts d'attaque
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

public:
    // Constructeurs et destructeur
    ClapTrap(void);  // Constructeur par défaut
    ClapTrap(std::string name);  // Constructeur paramétré pour initialiser le nom
    ClapTrap(ClapTrap const &copy);  // Constructeur de copie
    ~ClapTrap(void);  // Destructeur

    // Opérateurs
    ClapTrap &operator=(ClapTrap const &copy);  // Surcharge de l'opérateur d'affectation

    // Fonctions d'accès (getters) pour récupérer les valeurs des attributs privés
    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;

    // Fonctions membres pour les actions du ClapTrap
    void attack(const std::string &target);  // Fonction pour attaquer une cible
    void takeDamage(unsigned int amount);  // Fonction pour subir des dégâts
    void beRepaired(unsigned int amount);  // Fonction pour se réparer
    bool isGameOver(void);  // Fonction pour vérifier si le jeu est terminé
};

// Surcharge de l'opérateur de sortie pour afficher l'état du ClapTrap
std::ostream &operator<<(std::ostream &out, ClapTrap const &trap);

#endif
