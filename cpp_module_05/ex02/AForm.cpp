/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:07 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:10:08 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "create AForm default" << std::endl;
}

AForm::AForm(AForm const &other) : _name(other.getName()), _isSigned(false), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
	std::cout << "create AForm copy of " << other.getName() << std::endl;
	*this = other;
}

AForm::AForm(int signGrade, int executeGrade) : _name("default"), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "create AForm default with sign " << signGrade << " & exec " << executeGrade << std::endl;
	this->_checkGrades(signGrade, executeGrade);
}

AForm::AForm(std::string const &name) : _name(name), _isSigned(false), _signGrade(150), _executeGrade(150)
{
	std::cout << "create AForm " << this->_name << std::endl;
}

AForm::AForm(std::string const &name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "create AForm " << this->_name << " with sign " << signGrade << " & exec " << executeGrade << std::endl;
	this->_checkGrades(signGrade, executeGrade);
}

AForm::~AForm()
{
	std::cout << "destroy AForm " << this->_name << std::endl;
}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << "start assignation AForm to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

std::string const AForm::getName() const{return (this->_name);}
bool AForm::getIsSigned() const{return (this->_isSigned);}
int AForm::getSignGrade() const{return (this->_signGrade);}
int AForm::getExecuteGrade() const{return (this->_executeGrade);}

void AForm::_checkGrades(int signGrade, int executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if ((int)bureaucrat.getGrade() > this->_signGrade)
		throw Bureaucrat::GradeTooLowException();
	else if (!this->_isSigned)
	{
		std::cout << "\t" <<  bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_isSigned = true;
	}
	else
		std::cout << "\t" << bureaucrat.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form needs to be signed before executing");
}

std::ostream &operator<<(std::ostream &out, AForm *src)
{
	std::string isSigned = src->getIsSigned() ? " is signed" : " isn't signed";
	out << src->getName() << isSigned;
	out << ". Sign-grade: " << src->getSignGrade();
	out << ", execution-grade " << src->getExecuteGrade() << std::endl;
	return (out);
}
