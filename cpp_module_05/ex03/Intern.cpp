/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:11:41 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 17:00:46 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Implémentation du constructeur par défaut
Intern::Intern()
{
	std::cout << "create Intern" << std::endl;
}


// Implémentation du constructeur de copie
Intern::Intern(Intern const &other)
{
	std::cout << "create Intern copy" << std::endl;
	*this = other;
}

// Implémentation du destructeur
Intern::~Intern()
{
	std::cout << "destroy Intern" << std::endl;
}

// Implémentation de l'opérateur d'affectation
Intern &Intern::operator=(Intern const &other)
{
	std::cout << "start assignation Intern to other" << std::endl;
	if (this == &other)
		return(*this);
	return(*this);
}

// Déclaration et implémentation de fonctions globales pour créer des formulaires spécifiques
static AForm *makePresidential(std::string const &target){return (new PresidentialPardonForm(target));}
static AForm *makeRobotomy(std::string const &target){return (new RobotomyRequestForm(target));}
static AForm *makeShrubbery(std::string const &target){return (new ShrubberyCreationForm(target));}

// Implémentation de la méthode makeForm
AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
	// Tableau de pointeurs sur des fonctions pour générer des formulaires
	AForm *(*formGenerator[])(std::string const &target) = {&makePresidential, &makeRobotomy, &makeShrubbery};
	// Tableau des noms de formulaires correspondants
	std::string const formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	// Boucle pour trouver le formulaire correspondant
	for (int i = 0; i < 3; i++)
	{
		// Si le nom du formulaire correspond
		if (form == formNames[i])
		{
			AForm *generatedForm = formGenerator[i](target); // Génère le formulaire correspondant
			std::cout << "Intern creates " << form << std::endl; // Affiche que le stagiaire a créé le formulaire
			return (generatedForm); // Renvoie le formulaire généré
		}
	}
	// Affiche une erreur si le nom du formulaire n'existe pas
	std::cout << "\t" << "Intern can't make " << form << std::endl;
	// Renvoie NULL si aucun formulaire n'a été trouvé
	return (NULL);
}
