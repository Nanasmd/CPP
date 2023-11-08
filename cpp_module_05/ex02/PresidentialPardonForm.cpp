/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:42 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 16:46:37 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Définition du constructeur qui initialise la forme de pardon présidentiel
PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "create PresidentialPardonForm " << this->_target << std::endl;
}

// Définition du constructeur de copie
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm("PresidentialPardonForm", 25, 5), _target(other.getTarget())
{
	std::cout << "create PresidentialPardonForm copy of " << other.getName() << std::endl;
	*this = other;
}

// Définition du destructeur
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destroy PresidentialPardonForm " << this->_target << std::endl;
}

// Définition de l'opérateur d'assignation
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	std::cout << "start assignation PresidentialPardonForm to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

// Méthode d'accès à la cible du pardon
std::string PresidentialPardonForm::getTarget() const{return (this->_target);}

// Méthode d'exécution qui vérifie les autorisations et annonce le pardon de la cible
void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	if ((int)bureaucrat.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::cout << "\t" << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

// Surcharge de l'opérateur << pour l'affichage des détails du formulaire de pardon présidentiel
std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src)
{
	std::string isSigned = src->getIsSigned() ? " is signed" : " isn't signed";
	out << src->getName() << isSigned;
	out << ". Sign-grade: " << src->getSignGrade();
	out << ", execution-grade " << src->getExecuteGrade() << std::endl;
	return (out);
}