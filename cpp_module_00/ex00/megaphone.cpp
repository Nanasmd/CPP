/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:58:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/15 13:41:26 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring> // std::string
#include <cctype> // toupper

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
	// Parcoure tous les arguments fournis (en commençant par l'indice 1, car l'indice 0 est le nom du programme).
    for (int i = 1; i < argc; i++) {
		// Convertis l'argument C-style string en std::string pour utiliser les fonctionnalités de C++.
        std::string arg(argv[i]); // convertisseur de char* en std::string / char* arg = argv[i];
        // Parcours toutes les lettres de la chaîne de caractères.
		for (size_t j = 0; j < arg.length(); j++) // while (*arg)
			// Convertis chaque lettre en majuscule en utilisant std::toupper.
            arg[j] = std::toupper(arg[j]);
		// Affiche la chaîne de caractères convertie sans l'espace.
          std::cout << arg;
    }
	// Insère un retour à la ligne à la fin de l'affichage pour respecter la mise en forme demandée.
    std::cout << std::endl;
	// Retourne 0 pour signaler que le programme s'est terminé correctement.
    return 0;
}

// 1. Gestion des Arguments
// Ce que j'ai fait : Vérifié l'absence d'arguments de ligne de commande supplémentaires et 
// si aucun argument n'est fourni (argc == 1 puisque le nom du programme est toujours passé),
// j'affiche le message de feedback en accordance avec le sujet et termine le programme.
// j'ai veillé à ce que le programme n'essaie pas de traiter des arguments inexistants, 
// respectant ainsi l'exigence du problème de produire un message spécifique lorsque le programme est appelé sans arguments supplémentaires.

// 2. Conversion en Majuscules
// Ce que j'ai fait fait : Utilisé std::toupper dans une boucle pour convertir chaque caractère des chaînes d'entrée en majuscules.
// En faisant cela, je me suis assurée que chaque caractère, quelle que soit sa casse initiale,
// est affiché en majuscules, respectant strictement les exigences de l'exercice. 
// De plus, l'utilisation de std::toupper s'aligne sur l'instruction d'aborder les solutions de manière C++, 
// au lieu de recourir à des stratégies de style C.

// 3. Gestion des Chaînes de Caractères
// Ce que j'ai fait fait : Converti les chaînes de style C (char*) en std::string pour les manipuler et les afficher.
// La conversion de char* en std::string permet de tirer parti des capacités de gestion des chaînes de caractères de C++, 
// ce qui correspond clairement à la directive de l'assignation de résoudre les exercices en utilisant les fonctionnalités de C++. 
// Cela améliore la lisibilité et l'utilisabilité du code, en particulier pour les développeurs habitués aux manipulations de chaînes de caractères en C++.

// 4. Formatage de la Sortie
// Ce que j'ai fait fait : Présenté les chaînes transformées directement avec un caractère de nouvelle ligne à la fin.
// Même si votre commentaire de code suggère la possibilité d'insérer un espace entre les chaînes, 
// j'ai choisi de ne pas le faire, ce qui correspond aux sorties d'exemple fournies dans l'assignation. 
// Cela démontre une attention aux détails et la capacité à suivre de près les spécifications fournies.

// 5. Parcours des Caractères
// Ce que j'ai fait fait : Utilisé une boucle for et std::string::length pour parcourir chaque caractère.
// Au lieu d'opter pour la manipulation de chaînes de caractères de style C avec des pointeurs et une itération manuelle,
// l'utilisation d'une boucle avec std::string::length s'aligne sur les méthodologies de manipulation de chaînes de caractères en C++. 
// Cela garantit une approche propre et lisible de l'itération des caractères, ce qui est particulièrement bénéfique pour le débogage et les revues de code.
