/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:50 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/07 17:01:52 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "create RobotomyRequestForm " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm("RobotomyRequestForm", 72, 45), _target(other.getTarget())
{
	std::cout << "create RobotomyRequestForm copy of " << other.getName() << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "destroy RobotomyRequestForm " << this->_target << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	std::cout << "start assignation RobotomyRequestForm to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const{return (this->_target);}

static int RobotomyTry = 0;

// Suivi du nombre de tentatives : Si vous voulez garder une trace du nombre de fois que la méthode RobotomyRequestForm a été exécutée, 
// vous pourriez utiliser une variable static. Une variable membre static est partagée par toutes les instances de la classe. 
// Ainsi, elle peut être incrémentée chaque fois que la méthode execute est appelée pour refléter le nombre total de tentatives de robotomie, 
// indépendamment de l'instance de la forme spécifique qui est exécutée.

// Contrôle du comportement statique : Si la logique de la robotomie implique une sorte de simulation ou de décision pseudo-aléatoire 
// (comme mentionné dans votre description, où la robotomie réussit 50 % du temps), alors cette variable pourrait être utilisée pour contrôler ce comportement.
// Par exemple, elle pourrait être utilisée pour déterminer si une tentative particulière est réussie ou non, en alternant l'état à chaque appel.

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if ((int)bureaucrat.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else 
	{
		std::cout << "\t" << "zZzzzzzZZZZZzzZzZZzzZzZzz..." << std::endl;
		if (RobotomyTry++ % 2) //(std::rand() % 2)
			std::cout << "\t" << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "\t" << "Robotomization of " << this->_target << " failed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src)
{
	std::string isSigned = src->getIsSigned() ? " is signed" : " isn't signed";
	out << src->getName() << isSigned;
	out << ". Sign-grade: " << src->getSignGrade();
	out << ", execution-grade " << src->getExecuteGrade() << std::endl;
	return (out);
}
