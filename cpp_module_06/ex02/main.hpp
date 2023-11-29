/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:18:05 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 13:40:32 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define BOLD_RED	"\e[1;31m"
#define V_CYAN		"\e[0;38;5;44m"

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

// Fonctions d'Identification : Les fonctions identify démontrent comment 
// on peut déterminer le type d'un objet en utilisant des références et des pointeurs,
// en appliquant le casting dynamique pour tester si le cast est possible et déduire ainsi le type de l'objet.

// Randomisation : La fonction generate utilise la randomisation pour instancier différents types d'objets,
// ce qui peut être utile pour les tests et simulations nécessitant des comportements aléatoires.
