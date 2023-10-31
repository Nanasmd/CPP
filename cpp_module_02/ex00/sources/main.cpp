/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:07:31 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/25 17:49:34 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "*****************************************" << RESET << std::endl;
	std::cout << PINK << "*         nasamadi's C++ Piscine        *" << RESET << std::endl;
	std::cout << PINK << "*****************************************" << RESET << std::endl << std::endl;
}

int	main()
{
    mainHeader();
    
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}

// Explications

// int	main(void)
// {
        
// 	// Crée un objet "a" de type "Fixed". Le constructeur par défaut est appelé.
//     // La sortie sera : "Default constructor called"
// 	Fixed a;
// 	// Crée un objet "b" en utilisant le constructeur de copie avec "a" comme argument.
//     // La sortie sera : "Copy constructor called"
// 	Fixed b(a);
// 	// Crée un objet "c" de type "Fixed". Le constructeur par défaut est appelé.
//     // La sortie sera : "Default constructor called"
// 	Fixed c;
	
// 	c = b;

// 	// Utilise l'opérateur d'affectation pour assigner les valeurs de "b" à "c".
//     // La sortie sera : "Copy assignment operator called"
	
// 	std::cout << a.getRawBits() << std::endl;
// 	// Affiche la valeur interne de "a", qui est 0.
//     // Avant d'afficher la valeur, la méthode affichera : "getRawBits member function called"
// 	std::cout << b.getRawBits() << std::endl;
// 	// Affiche la valeur interne de "b", qui est également 0.
//     // Avant d'afficher la valeur, la méthode affichera : "getRawBits member function called"
// 	std::cout << c.getRawBits() << std::endl;
// 	// Affiche la valeur interne de "c", qui est également 0.
//     // Avant d'afficher la valeur, la méthode affichera : "getRawBits member function called"
	
// 	return 0; // Fin du programme
// }

// Ce code est une démonstration des mécanismes de base de la classe Fixed et montre comment les constructeurs, l'opérateur d'affectation et la méthode getRawBits fonctionnent et interagissent.

// int main(void)
// {
//     mainHeader();
        
//     Fixed a;
//     std::cout << YELLOW << "Valeur initiale de a: " << RESET << GREEN << a.getRawBits() << RESET << std::endl;
//     a.setRawBits(42); // On change la valeur interne de "a" pour être 42
//     std::cout << YELLOW << "Valeur modifiee de a: " << RESET << GREEN << a.getRawBits() << RESET << std::endl;
    
//     Fixed b(a); // On crée une copie "b" de "a"
//     std::cout << YELLOW << "Valeur initiale de b: " << RESET << GREEN << b.getRawBits() << RESET << std::endl;

//     std::cout << YELLOW << "Valeur de a (après modification): " << RESET << GREEN << a.getRawBits() << RESET << std::endl;
//     std::cout << YELLOW << "Valeur de b (après copie): " << RESET << GREEN << b.getRawBits() << RESET << std::endl;

//     a.setRawBits(21); // On change la valeur interne de "a" après avoir fait la copie
//     std::cout << YELLOW << "Valeur de a (après deuxième modification): " << RESET << GREEN << a.getRawBits() << RESET << std::endl;
//     std::cout << YELLOW << "Valeur de b (après modification de a): " << RESET << GREEN << b.getRawBits() << RESET << std::endl;

//     return 0;
// }
