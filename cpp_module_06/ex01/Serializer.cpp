/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:38:09 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 13:17:12 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Le constructeur par défaut.
Serializer::Serializer(){}

// Le constructeur de copie. Ici, il ne fait rien, car la classe ne contient pas de ressources gérées.
Serializer::Serializer(Serializer const &other) {*this = other;}

// Le destructeur.
Serializer::~Serializer(){}

// L'opérateur d'assignation qui ne fait rien ici, car la classe n'a pas de membres non-statiques.
Serializer &Serializer::operator=(Serializer const &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

// Méthode serialize qui prend un pointeur vers Data et retourne une valeur de type uintptr_t.
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr)); // Utilisation de reinterpret_cast pour la conversion de type.
}

// Méthode deserialize qui prend un uintptr_t et retourne un pointeur vers Data.
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw)); // Utilisation de reinterpret_cast pour la conversion de type.
}


// Sérialisation : Bien que cet exercice ne concerne pas la sérialisation au sens traditionnel du terme, 
// qui consiste à convertir un objet en un flux d'octets, il traite d'une forme simpliste de sérialisation : 
// la conversion d'un pointeur en un type uintptr_t et vice-versa. Cela peut être vu comme une forme de sérialisation 
// où les "données" sont juste l'adresse en mémoire.

// Pointeurs et Types Entiers : Comprendre la relation entre les pointeurs et les types entiers,
// en particulier le type uintptr_t qui est garanti de pouvoir contenir un pointeur. 
// Ceci est important pour les opérations de bas niveau où vous pourriez avoir besoin de stocker des pointeurs 
// dans des variables entières ou effectuer certaines opérations qui nécessitent une représentation entière d'un pointeur.

// Casting de Types : L'exercice implique l'utilisation de reinterpret_cast, 
// qui est un type de casting permettant de convertir n'importe quel type de pointeur en n'importe quel autre type de pointeur,
//ainsi que des pointeurs vers ou depuis des types intégraux. C'est un outil puissant et dangereux qui doit être utilisé avec prudence, 
// et l'exercice offre un environnement contrôlé pour s'exercer à l'utiliser.

// Méthodes de Classe Statiques : En implémentant les méthodes serialize et deserialize comme statiques,
// vous pratiquez la création de fonctions utilitaires qui ne nécessitent pas une instance d'objet pour être utilisées. 
// Ce modèle est courant pour les classes qui fournissent des services ou des opérations mais qui n'ont pas besoin de maintenir un état.
