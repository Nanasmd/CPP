/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhonebook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:16:00 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/15 13:50:34 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClassPhonebook.hpp"

/*
** constructor
*/
Phonebook::Phonebook() {}

/*
** destructor
*/
Phonebook::~Phonebook() {}

// En C++98, les constructeurs (constructors) et les destructeurs (destructors) sont des éléments essentiels de la programmation orientée objet. Voici une explication de ces concepts :

// Constructeurs :
// Un constructeur est une méthode spéciale appelée lorsqu'un objet d'une classe est créé. Il est responsable de l'initialisation des membres de l'objet.
// En C++98, une classe peut avoir plusieurs constructeurs, chacun ayant une liste d'initialisation spécifique.
// Les constructeurs peuvent avoir des paramètres, ce qui permet d'initialiser les membres de la classe avec des valeurs spécifiques lors de la création de l'objet.
// Si vous ne fournissez pas de constructeur pour votre classe, le compilateur en générera un par défaut.
// Exemple de constructeur en C++98 :

// class MaClasse {
// public:
//     MaClasse() {
//         // Constructeur par défaut
//         // Vous pouvez initialiser les membres ici
//     }

//     MaClasse(int valeurInitiale) {
//         // Constructeur avec un paramètre
//         // Initialise la classe avec la valeur fournie
//     }
// };

// Destructeur :
// Un destructeur est également une méthode spéciale, mais il est appelé lorsqu'un objet est détruit, généralement à la fin de sa portée.
// Le destructeur a le même nom que la classe précédé du symbole de tilde (~).
// En C++98, les destructeurs n'ont généralement pas de paramètres, car ils sont destinés à effectuer des tâches de nettoyage ou de libération de ressources associées à l'objet.
// Si vous ne fournissez pas de destructeur, le compilateur en générera un par défaut qui ne fera rien de particulier.
// Exemple de destructeur en C++98 :

// class MaClasse {
// public:
//     MaClasse() {
//         // Constructeur
//     }

//     ~MaClasse() {
//         // Destructeur
//         // Vous pouvez effectuer des opérations de nettoyage ici
//     }
// };

// Il est important de noter que les destructeurs peuvent être utilisés pour libérer des ressources allouées dynamiquement,
// telles que la mémoire allouée avec new. Dans ces cas, le destructeur doit être implémenté pour garantir que les ressources sont correctement libérées.

// En résumé, les constructeurs sont utilisés pour initialiser des objets lors de leur création,
// tandis que les destructeurs sont utilisés pour effectuer des opérations de nettoyage lors de la destruction d'objets.
// Ensemble, ils contribuent à la gestion des objets en C++98.

// En l'occurence dans cet exercices, mes constructeurs et destructeurs vides peuvent être appropriés lorsque votre classe n'a pas besoin de personnaliser 
// le processus d'initialisation ou de libération de ressources, ou lorsque vous prévoyez d'étendre la classe dans le futur. 
// Si votre classe ne nécessite pas de traitement spécial dans ces méthodes, vous pouvez laisser le compilateur générer les versions par défaut à la place.