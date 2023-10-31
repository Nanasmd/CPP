/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:16:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/15 17:59:08 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhonebook.hpp"
#include <cstdlib> // for std::exit

int	main() {
	Phonebook	phonebook;
	std::string	command;
	const int	MAX_CONTACTS = 8;
	int			i = 0;
	int			num_contacts = 0;

	command = print_welcome_message(command);
	while (command != "EXIT" && command != "exit") {
		if (command == "ADD" || command == "add") {
			if (i == 8)
				i = 0;
			phonebook.contact[i] = add_new_contact();
			i++;
			if (num_contacts < MAX_CONTACTS)
				num_contacts++;
		}
		else if (command == "SEARCH" || command == "search") {
			if (num_contacts > 0) {
				show_all_contacts(phonebook.contact, num_contacts);
				choose_contact(phonebook.contact, num_contacts);
			}
			else
				std::cout << "Empty phonebook" << std::endl;
		}
		else
			std::cout 
				<< BOLD_RED << "Invalid command" << std::endl << RESET;
		std::cout
			<< LILAC << "Type your command: " << RESET;
		getline(std::cin, command);
		// Check for EOF or input failure.
    	if (!std::cin || std::cin.eof()) {
        std::cout << BOLD_RED << "\nExiting due to user request or input error." << RESET << std::endl;
        std::exit(1);  // Forcefully exit the program.
		return 1;
    	}
	}
	std::cout << PURPLE << "Bye! =)" << std::endl << RESET;
	return 0;
}

std::string	print_welcome_message(std::string command) {
	std::cout 
			<< PINK << "Welcome to nasamadi's Phonebook" << RESET << std::endl;
	std::cout
			<< V_CYAN
			<< "Type:" << std::endl 
			<< "ADD to add a new contact" << std::endl 
			<< "SEARCH to search a contact" << std::endl
			<< "EXIT to exit" << std::endl
			<< RESET;
	std::cout
		<< LILAC << "Type your command: " << RESET;
	getline(std::cin, command);
	// Check for EOF or input failure.
	if (!std::cin || std::cin.eof()) {
    std::cout << BOLD_RED << "\nExiting due to user request or input error." << RESET << std::endl;
	std::exit(1);  // Forcefully exit the program.
	}
	return command;
}

// Présentation

// Objectif : La tâche consiste à créer une application basique de carnet d'adresses. Le carnet gère les informations de contact. Il permet aux utilisateurs d'ajouter un nouveau contact, de rechercher parmi les contacts existants, et d'afficher des informations détaillées sur un contact choisi.

// Conception & Architecture

// Conception Modulaire :
// Le code est modulaire, séparant différentes fonctionnalités dans des fichiers distincts (add.cpp, search.cpp, ClassContacts.cpp, etc.), améliorant la lisibilité et la maintenabilité.

// Conception des Classes :

// ClassContacts gère les informations individuelles des contacts, avec des méthodes de paramétrage et d’accès pour l’encapsulation.
// ClassPhonebook (bien que minimale) est conçue pour gérer les contacts mais manque de fonctionnalité dans les extraits de code fournis.

// Interaction Utilisateur :

// L'application interagit avec les utilisateurs via des entrées/sorties console.
// Des invites guident l'utilisateur pour effectuer des actions spécifiques (AJOUTER, RECHERCHER, QUITTER).
// L'application fournit des retours à l'utilisateur en cas d'entrées invalides.

// Fonctionnalités Clés

// Ajouter des Contacts (add.cpp & fonction add_new_contact) :
// Collecte et valide les entrées de l'utilisateur (à l'aide de fonctions auxiliaires comme is_not_empty_and_alpha et is_not_empty_and_numeric) pour divers champs, tels que le nom, le numéro de téléphone et le secret le plus sombre.
// Des messages d'erreur guident l'utilisateur pour fournir une entrée valide, améliorant l'expérience utilisateur.

// Rechercher des Contacts (search.cpp) :
// Fournit une vue résumée de tous les contacts et permet aux utilisateurs de sélectionner un contact pour voir des informations détaillées.
// Assure que les entrées des utilisateurs sont validées (un ID dans la plage).
// Offre une gestion élégante des erreurs d'entrée potentielles et des sorties inattendues.

// Afficher des Contacts :
// La vue résumée (10 caractères max par champ, tronquant et ajoutant un point si nécessaire, effectué à l'aide des fonctions trim et print_contacts) assure un affichage compact.
// La vue détaillée affiche toutes les informations sur un contact choisi.

// Gérer les Commandes Utilisateur (main.cpp) :

// Traite les commandes de l'utilisateur, assurant un bon déroulement à travers l'application (basculant entre l'ajout de contacts, la recherche et la sortie).
// Utilise une boucle pour une interaction utilisateur continue jusqu'à réception de la commande "QUITTER".
// Gestion des Erreurs
// Le code tente de gérer les problèmes potentiels d'exécution, tels que EOF et les entrées invalides, fournissant des retours et des actions appropriés (comme une sortie propre).