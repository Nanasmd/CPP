/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContacts.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:15:47 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/15 13:45:32 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContacts.hpp"

/*
** constructor
*/

Contacts::Contacts() {}

/*
** destructor
*/

Contacts::~Contacts() {}

/*
** getters and setters
*/

std::string Contacts::get_first_name() const {
	return this->_first_name;
}

void	Contacts::set_first_name(std::string first_name) {
	this->_first_name = first_name;
}

std::string Contacts::get_last_name() const {
	return this->_last_name;
}

void	Contacts::set_last_name(std::string last_name) {
	this->_last_name = last_name;
}

std::string Contacts::get_nickname() const {
	return this->_nickname;
}

void	Contacts::set_nickname(std::string nickname) {
	this->_nickname = nickname;
}

std::string Contacts::get_phone_number() const {
	return this->_phone_number;
}

void	Contacts::set_phone_number(std::string phone_number) {
	this->_phone_number = phone_number;
}

std::string Contacts::get_darkest_secret() const {
	return this->_darkest_secret;
}

void	Contacts::set_darkest_secret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}

// En C++98, les getter et les setter sont des méthodes utilisées pour accéder aux membres privés d'une classe. 
// Ils sont généralement utilisés pour encapsuler les données d'une classe et pour permettre un contrôle plus précis sur la façon dont ces données sont accessibles et modifiées. 
// Voici comment ils fonctionnent :

// Getter :
// Un getter est une méthode qui permet d'obtenir la valeur d'un membre privé de la classe depuis l'extérieur de la classe.
// Il est déclaré comme une fonction publique de la classe, et il ne modifie pas la valeur du membre.
// Le nom d'une méthode getter commence généralement par "get" suivi du nom du membre.
// Il retourne la valeur du membre privé.

// Exemple de getter en C++98 :

// class MaClasse {
// private:
//     int maVariablePrivee;
// public:
//     int getMaVariablePrivee() const {
//         return maVariablePrivee;
//     }
// };

// Dans cet exemple, getMaVariablePrivee est le getter qui permet d'obtenir la valeur de maVariablePrivee.

// Setter :
// Un setter est une méthode qui permet de modifier la valeur d'un membre privé de la classe depuis l'extérieur de la classe.
// Il est également déclaré comme une fonction publique de la classe.
// Le nom d'une méthode setter commence généralement par "set" suivi du nom du membre.
// Il prend un argument qui est la nouvelle valeur du membre, puis met à jour la valeur du membre privé avec cette nouvelle valeur.

// Exemple de setter en C++98 :

// class MaClasse {
// private:
//     int maVariablePrivee;
// public:
//     void setMaVariablePrivee(int nouvelleValeur) {
//         maVariablePrivee = nouvelleValeur;
//     }
// };

// Dans cet exemple, setMaVariablePrivee est le setter qui permet de modifier la valeur de maVariablePrivee.

// L'utilisation de getters et de setters permet de garantir l'encapsulation des données en cachant les membres privés de la classe,
// tout en permettant un contrôle précis sur la manière dont ces données sont accessibles et modifiées depuis l'extérieur de la classe.
// Cela peut être utile pour maintenir la cohérence des données et appliquer des vérifications ou des opérations spécifiques lors de la lecture ou de l'écriture de ces données.
