/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:07:12 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:43:14 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// --------------------------- CONSTRUCTEURS ----------------------------------

// Constructeur par défaut
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "create Bureaucrat default" << std::endl;
}

// Constructeur avec nom spécifié
Bureaucrat::Bureaucrat(std::string const &name) : _name(name), _grade(150)
{
	std::cout << "create Bureaucrat " << this->_name << std::endl;
}

// Constructeur avec grade spécifié
Bureaucrat::Bureaucrat(int grade) : _name("default")
{
	std::cout << "create Bureaucrat default with grade " << grade << std::endl;
	this->_setGrade(grade);
}

// Constructeur avec nom et grade spécifiés
Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	std::cout << "create Bureaucrat " << this->_name << " with grade " << grade << std::endl;
	this->_setGrade(grade);
}

// Constructeur de copie
Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
	std::cout << "create Bureaucrat copy of " << other.getName() << std::endl;
	*this = other;
}

// Opérateur d'affectation
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "start assignation Bureaucrat to other" << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return (*this);
}

// Destructeur
Bureaucrat::~Bureaucrat()
{
	std::cout << "destroy Bureaucrat " << this->_name << std::endl;
}

// Accesseur pour obtenir le nom du bureaucrate
std::string const Bureaucrat::getName() const{return (this->_name);}
// Accesseur pour obtenir le grade du bureaucrate
size_t Bureaucrat::getGrade() const{return (this->_grade);}

// Méthode privée pour définir le grade du bureaucrate, avec vérification des limites
void Bureaucrat::_setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

// Méthode pour augmenter et diminuer le grade du bureaucrate
void Bureaucrat::incrementGrade(){this->_setGrade(this->_grade - 1);}
void Bureaucrat::decrementGrade(){this->_setGrade(this->_grade + 1);}

// Méthode pour gérer l'exception lorsque le grade est trop haut ou trop bas
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

// Surcharge de l'opérateur << pour afficher les informations du bureaucrate
std::ostream &operator<<(std::ostream &out, Bureaucrat *other)
{
	out << other->getName() << ", bureaucrat grade " << other->getGrade() << std::endl;
	return (out);
}
