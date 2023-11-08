/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:45 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 16:45:21 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Avant-déclaration des classes pour éviter les inclusions circulaires
class Bureaucrat;
class AForm;

// Classe PresidentialPardonForm, héritée de la classe AForm
class PresidentialPardonForm : public AForm
{
	private:
		std::string const _target; // Cible du pardon présidentiel

		PresidentialPardonForm(); // Constructeur privé par défaut (non utilisé)

	public:
		// Constructeur prenant un nom de cible comme paramètre
		PresidentialPardonForm(std::string const &target);
		// Constructeur de copie
		PresidentialPardonForm(PresidentialPardonForm const &other);
		// Destructeur
		~PresidentialPardonForm();

		// Opérateur d'assignation
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

		// Méthode pour obtenir la cible du pardon
		std::string getTarget() const;

		// Méthode d'exécution du formulaire qui annonce le pardon de la cible
		virtual void execute(Bureaucrat const &bureaucrat) const;
};

// Surcharge de l'opérateur << pour afficher les informations de la forme de pardon présidentiel
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src);
