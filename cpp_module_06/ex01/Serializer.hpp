/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:38:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 13:12:50 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

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

// Definition du struct Data qui contient des informations personnelles
typedef struct Data
{
	std::string name; // Nom de la personne
	size_t 		age; // Age de la personne
	Data 		*next; // Pointeur vers le prochain Data dans une liste chaînée
}				Data;

// La classe Serializer est utilisée pour convertir un pointeur en un entier 
// et vice-versa, sans faire de véritable sérialisation de données.
class Serializer
{
	private:
		Serializer(); // Constructeur privé pour empêcher l'instanciation de la classe.
		Serializer(Serializer const &other); // Constructeur de copie privé pour empêcher la copie.
		Serializer &operator=(Serializer const &other); // Operateur d'assignation privé pour empêcher l'assignation.
		~Serializer(); // Destructeur
	
	public:
		// Méthode statique qui convertit un pointeur Data* en uintptr_t.
		static uintptr_t serialize(Data *ptr);
		// Méthode statique qui convertit un uintptr_t en pointeur Data*.
		static Data *deserialize(uintptr_t raw);
};
