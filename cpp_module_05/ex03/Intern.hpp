/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:11:44 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 16:57:43 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // Assure que le fichier d'en-tête ne soit inclus qu'une seule fois à la compilation

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm; // Déclaration anticipée de la classe AForm

// Déclaration de la classe Intern
class Intern
{
	public:
		Intern(); // Constructeur par défaut
		Intern(Intern const &other); // Constructeur de copie
		~Intern(); // Destructeur
		
		Intern &operator=(Intern const &other); // Opérateur d'affectation

		// Méthode pour créer un formulaire
		AForm *makeForm(std::string const &form, std::string const &target);
};
