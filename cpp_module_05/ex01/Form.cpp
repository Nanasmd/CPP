/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:09:42 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 16:38:40 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// --------------------------- CONSTRUCTEURS ----------------------------------

// Constructeur par défaut
Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "create Form default" << std::endl;
}

// Constructeur de copie
Form::Form(Form const &other) : _name(other.getName()), _isSigned(false), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << "create Form copy of " << other.getName() << std::endl;
	*this = other;
}

// Constructeur avec les grades de signature et d'exécution
Form::Form(int signGrade, int executeGrade) : _name("default"), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "create Form default with sign-grade" << signGrade << " and execution-grade " << executeGrade << std::endl;
	this->_checkGrades(signGrade, executeGrade);
}

// Constructeur spécifiant le nom du formulaire
Form::Form(std::string const &name) : _name(name), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "create Form " << this->_name << std::endl;
}

// Constructeur complet avec nom, grade de signature et d'exécution
Form::Form(std::string const &name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "create Form " << this->_name << " with sign-grade " << signGrade << " and execution-grade " << executeGrade << std::endl;
	this->_checkGrades(signGrade, executeGrade);
}

// Destructeur
Form::~Form()
{
	std::cout << "destroy Form " << this->_name << std::endl;
}

// Opérateur d'assignation
Form &Form::operator=(Form const &other)
{
	std::cout << "start assignation Form to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

// Getters pour accéder aux attributs privés
std::string const Form::getName() const{return (this->_name);}
bool Form::getIsSigned() const{return (this->_isSigned);}
int Form::getSignGrade() const{return (this->_signGrade);}
int Form::getExecuteGrade() const{return (this->_executeGrade);}

// Méthode pour vérifier la validité des grades
void Form::_checkGrades(int signGrade, int executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

// Méthode pour qu'un bureaucrate signe le formulaire
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if ((int)bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else if (!this->_isSigned)
	{
		std::cout << "\t" << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_isSigned = true;
	}
	else
		std::cout << "\t" << bureaucrat.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
}

// Exceptions personnalisées pour les erreurs de grade
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// Surcharge de l'opérateur d'insertion pour afficher les informations du formulaire
std::ostream &operator<<(std::ostream &out, Form *form)
{
	std::string isSigned = form->getIsSigned() ? "is signed" : "isn't signed";
	out << form->getName() << " Form " << isSigned;
	out << ". Sign-grade: " << form->getSignGrade();
	out << ", execution-grade: " << form->getExecuteGrade();
	out << std::endl;
	return (out);
}
