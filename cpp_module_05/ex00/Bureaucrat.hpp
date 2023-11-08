/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:07:15 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 17:24:21 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once // // Empêche les inclusions multiples du fichier d'en-tête

#include <iostream> // Inclusion pour les entrées/sorties
#include <string> // Inclusion pour l'utilisation de chaînes de caractères

// Déclaration de la classe Bureaucrat
class Bureaucrat
{
	private:
		// Nom du bureaucrate, constante car il ne change pas après l'initialisation
		std::string const _name;
		// Grade du bureaucrate, entre 1 et 150
		size_t	_grade;

		// Méthode privée pour régler le grade, lance une exception si le grade est hors limites
		void _setGrade(int grade);
	
	public:
		// Constructeurs et destructeur
		Bureaucrat();
		Bureaucrat(std::string const &name);
		Bureaucrat(int grade);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		// Surcharge de l'opérateur d'affectation
		Bureaucrat &operator=(Bureaucrat const &other);

		// Accesseurs pour le nom et le grade
		std::string const getName() const;
		size_t getGrade() const;

		// Méthodes pour incrémenter et décrémenter le grade
		void incrementGrade();
		void decrementGrade();

		// Classes d'exception pour les grades trop élevés ou trop bas
		class GradeTooHighException : public std::exception
		{
			public:
				// Méthode pour obtenir le message d'erreur
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

// Surcharge de l'opérateur << pour afficher un bureaucrate
std::ostream &operator<<(std::ostream &out, Bureaucrat *other);