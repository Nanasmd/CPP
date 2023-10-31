/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContacts.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:14:45 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/15 16:32:28 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCONTACTS_HPP
# define CLASSCONTACTS_HPP

#include <string>

class Contacts
{
	public:

		Contacts();
		~Contacts();

		std::string	get_first_name(void) const;
		void		set_first_name(std::string first_name);

		std::string	get_last_name(void) const;
		void		set_last_name(std::string last_name);

		std::string	get_nickname(void) const;
		void		set_nickname(std::string nickname);		

		std::string	get_phone_number(void) const;
		void		set_phone_number(std::string phone_number);

		std::string	get_darkest_secret(void) const;
		void		set_darkest_secret(std::string darkest_secret);

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif

// Déclaration d'une classe :

// Pour déclarer une classe, utilisez le mot-clé class, suivi du nom de la classe et de l'accolade ouvrante { pour définir le contenu de la classe. 
// Les membres de classe sont définis à l'intérieur de cette accolade.

// Exemple de déclaration d'une classe en C++98 :

// class MaClasse {
// private:
//     int variablePrivee;

// public:
//     // Méthodes publiques
//     void SetValeur(int valeur);
//     int GetValeur();
// };

// Dans cet exemple, MaClasse est le nom de la classe, et variablePrivee est un membre de classe privé.

// Membres de classe :

// Les membres de classe peuvent être publics, privés ou protégés, contrôlant ainsi leur visibilité et leur accessibilité depuis l'extérieur de la classe.
// Les membres privés sont accessibles uniquement à l'intérieur de la classe, tandis que les membres publics sont accessibles depuis l'extérieur.
// Les membres protégés sont similaires aux membres privés, mais ils sont accessibles à partir des classes dérivées.
// Implémentation des méthodes :

// Vous pouvez implémenter les méthodes de classe (fonctions membres) à l'extérieur de la déclaration de la classe. Les méthodes sont des fonctions qui effectuent des opérations sur les membres de la classe.

// Exemple d'implémentation de méthodes en C++98 :

// void MaClasse::SetValeur(int valeur) {
//     variablePrivee = valeur;
// }

// int MaClasse::GetValeur() {
//     return variablePrivee;
// }

// Ces méthodes SetValeur et GetValeur sont responsables de la modification et de la récupération de la valeur de variablePrivee.

// Création d'objets :

// Pour utiliser une classe, vous devez créer des objets de cette classe. Cela se fait en instanciant la classe à l'aide du nom de la classe suivi de parenthèses.

// Exemple de création d'un objet en C++98 :

// MaClasse monObjet;

// Accès aux membres :

// Vous pouvez accéder aux membres de classe à l'aide de l'opérateur . (point).

// Exemple d'accès aux membres en C++98 :

// monObjet.SetValeur(42);
// int valeur = monObjet.GetValeur();

// Dans cet exemple, nous utilisons monObjet pour appeler les méthodes de la classe MaClasse.

// Destructeur :

// En C++98, vous pouvez également définir un destructeur (méthode spéciale nommée ~MaClasse()) qui est appelé lorsque l'objet est détruit. 
// Cela peut être utilisé pour libérer des ressources ou effectuer des opérations de nettoyage.

// Ceci est une introduction de base à la création et à l'utilisation de classes en C++98. 
// Les classes sont une composante clé en C++ et permettent d'organiser le code de manière plus structurée,
// de favoriser l'encapsulation des données et de réutiliser du code.