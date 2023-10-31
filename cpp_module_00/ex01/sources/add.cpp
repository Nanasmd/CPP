/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:15:33 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/16 14:01:33 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassPhonebook.hpp"
#include <cctype>
#include <cstdlib> // for std::exit

// Vérifie si la chaîne donnée ne contient que des chiffres.
bool is_numeric(const std::string& str) {
    for (std::size_t i = 0; i < str.size(); ++i) {
        // Si le caractère actuel n'est pas un chiffre, retourne false.
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true; // Tous les caractères sont des chiffres.
}

// Vérifie si la chaîne donnée ne contient que des lettres.
bool is_alpha(const std::string& str) {
    for (std::size_t i = 0; i < str.size(); ++i) {
        // Si le caractère actuel n'est pas une lettre, retourne false.
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true; // Tous les caractères sont des lettres.
}

// Vérifie si la chaîne donnée n'est pas vide.
bool is_not_empty(const std::string& str) {
    return !str.empty(); // Retourne true si la chaîne n'est pas vide.
}

// Vérifie si la chaîne donnée n'est pas vide et ne contient que des lettres.
bool is_not_empty_and_alpha(const std::string& str) {
    return !str.empty() && is_alpha(str);
}

// Vérifie si la chaîne donnée n'est pas vide et ne contient que des chiffres.
bool is_not_empty_and_numeric(const std::string& str) {
    return !str.empty() && is_numeric(str);
}

// Définit un alias pour les pointeurs de fonctions qui prennent une std::string et retournent un bool.
typedef bool (*ValidatorFunc)(const std::string&);

// Demande une information à l'utilisateur et la valide avec la fonction donnée. 
void get_info(const char* prompt, std::string& info, ValidatorFunc validate, const char* error_message) {
    do {
        info.clear(); // Efface tout contenu précédent de la chaîne info.
        std::cout << BLUE << prompt << RESET; // Affiche le message d'invite (en bleu si les constantes de couleur sont définies).
        // Tente de lire une ligne de l'entrée standard.
        if (!getline(std::cin, info) || std::cin.eof()) {
            // Affiche un message d'erreur et termine le programme si la lecture échoue ou si l'utilisateur demande à quitter.
            std::cout << BOLD_RED << "\nExiting due to user request or input error." << RESET << std::endl;
            std::exit(1);
        }
        // Si la validation échoue, affiche un message d'erreur.
        if (!validate(info)) {
            std::cout << BOLD_RED << error_message << RESET;
        }
    } while (!validate(info)); // Continue de demander tant que la validation échoue.
}

// Ajoute un nouveau contact en demandant toutes les informations nécessaires à l'utilisateur.
Contacts add_new_contact() {
    Contacts new_contact; // Crée un nouvel objet contact.
    std::string info; // Chaîne pour stocker les informations temporaires.

    // Obtient et valide le prénom.
    get_info("First name: ", info, is_not_empty_and_alpha, "First name should be non-empty and contain only letters. Try again:\n");
    new_contact.set_first_name(info); // Attribue le prénom au nouveau contact.

    // Obtient et valide le nom de famille.
    get_info("Last name: ", info, is_not_empty_and_alpha, "Last name should be non-empty and contain only letters. Try again:\n");
    new_contact.set_last_name(info); // Attribue le nom de famille au nouveau contact.

    // Obtient et valide le surnom.
    get_info("Nickname: ", info, is_not_empty, "Nickname cannot be empty. Try again:\n");
    new_contact.set_nickname(info); // Attribue le surnom au nouveau contact.

    // Obtient et valide le numéro de téléphone.
    get_info("Phone number: ", info, is_not_empty_and_numeric, "Phone number should be non-empty and contain only digits. Try again:\n");
    new_contact.set_phone_number(info); // Attribue le numéro de téléphone au nouveau contact.

    // Obtient et valide le secret le plus sombre.
    get_info("Darkest secret: ", info, is_not_empty, "Darkest secret cannot be empty. Try again:\n");
    new_contact.set_darkest_secret(info); // Attribue le secret le plus sombre au nouveau contact.

    return new_contact; // Retourne le nouveau contact créé.
}


// Contacts	add_new_contact() {
// 	Contacts	new_contact;
// 	std::string	info;

// 	do {
//     info.clear();
//     std::cout << BLUE << "First name: " << RESET;
//     getline(std::cin, info);
//     if (info.empty() || !is_alpha(info)) {
//         std::cout << BOLD_RED << "First name should be non-empty and contain only letters. Try again:\n" << RESET;
//     	}
// 	} while (info.empty() || !is_alpha(info));
// 	new_contact.set_first_name(info);
//     do {
// 	info.clear();
//     std::cout << BLUE << "Last name: " << RESET;
//     getline(std::cin, info);
//     if (info.empty() || !is_alpha(info)) {
// 	    std::cout << BOLD_RED << "Last name should be non-empty and contain only letters. Try again:\n" << RESET;
//         }
//     } while (info.empty() || !is_alpha(info));
//     new_contact.set_last_name(info);	
//     do {
// 	info.clear();
//     std::cout << BLUE << "Nickname: " << RESET;
//     getline(std::cin, info);
//     if (info.empty()) {
//         std::cout << BOLD_RED << "Nickname cannot be empty. Try again:\n" << RESET;
//         }
//     } while (info.empty());
//     new_contact.set_nickname(info);	
// 	do {
// 	info.clear();
//     std::cout << BLUE << "Phone number: " << RESET;
//     getline(std::cin, info);
//     if (info.empty() || !is_numeric(info)) {
//         std::cout << BOLD_RED << "Phone number should be non-empty and contain only digits. Try again:\n" << RESET;
//         }
//     } while (info.empty() || !is_numeric(info));
//     new_contact.set_phone_number(info);
//     do {
// 	info.clear();
//     std::cout << BLUE << "Darkest secret: " << RESET;
//     getline(std::cin, info);
//     if (info.empty()) {
//         std::cout << BOLD_RED << "Darkest secret cannot be empty. Try again:\n" << RESET;
//         }
//     } while (info.empty());
//     new_contact.set_darkest_secret(info);	
// 	return (new_contact);
// }


// Contacts	add_new_contact() {
// 	Contacts	new_contact;
// 	std::string	info;

// 	std::cout << BLUE << "First name: " << RESET;
// 	getline(std::cin, info);
// 	new_contact.set_first_name(info);
// 	std::cout << BLUE << "Last name: " << RESET;
// 	getline(std::cin, info);
// 	new_contact.set_last_name(info);
// 	std::cout << BLUE << "Nickname: " << RESET;
// 	getline(std::cin, info);
// 	new_contact.set_nickname(info);
// 	std::cout << BLUE << "Phone number: " << RESET;
// 	getline(std::cin, info);
// 	new_contact.set_phone_number(info);
// 	std::cout << BLUE << "Darkest secret: " << RESET;
// 	getline(std::cin, info);
// 	new_contact.set_darkest_secret(info);
// 	return (new_contact);
// }

