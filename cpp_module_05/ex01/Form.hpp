/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:09:46 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 16:41:41 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

// Avant-déclaration de la classe Bureaucrat pour éviter une dépendance circulaire
class Bureaucrat;

// Déclaration de la classe Form
class Form
{
	private:
		std::string const _name; // Nom constant du formulaire
		bool		_isSigned; // Booléen indiquant si le formulaire est signé
		int const	_signGrade; // Grade requis pour signer le formulaire
		int const	_executeGrade; // Grade requis pour exécuter le formulaire

		// Méthode privée pour vérifier la validité des grades lors de la création
		void _checkGrades(int signGrade, int executeGrade);
	
	public:
		// Constructeurs
		Form();
		Form(Form const &other);
		Form(int signGrade, int executeGrade);
		Form(std::string const &name);
		Form(std::string const &name, int signGrade, int executeGrade);
		// Destructeur
		~Form();

		// Opérateur d'assignation
		Form &operator=(Form const &other);

		// Accesseurs pour les attributs privés
		std::string const getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		// Méthode pour tenter de signer le formulaire avec un bureaucrate
		void beSigned(Bureaucrat &bureaucrat);

		// Classes d'exceptions pour gérer les erreurs de grade
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

// Surcharge de l'opérateur << pour permettre l'affichage des informations du formulaire via un flux
std::ostream &operator<<(std::ostream &out, Form *form);