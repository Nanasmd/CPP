/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:15:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:15:16 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Jhon doe"), gradeSign(LOW_GRADE), gradeExecute(LOW_GRADE), isSigned(false)
{
	std::cout << "Unidentified Form Constructor called." << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called." << std::endl;
}

Form::Form(std::string _name, int _gradeSign, int _gradeExecute): 
	name(_name), gradeSign(_gradeSign), gradeExecute(_gradeExecute), isSigned(false)
{
	std::cout << "Form Constructor called." << std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form const &src):
	name(src.name), gradeSign(src.gradeSign), gradeExecute(src.gradeExecute)
{
	std::cout << "Form copy Constructor called." << std::endl;
	if (gradeSign < 1 || gradeExecute < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form &Form::operator=(Form const &src)
{
	std::cout << "Form equal operator called." << std::endl;
	if (this != &src)
	{
		std::cout << "Form copy Constructor called." << std::endl;
		if (src.gradeSign < 1 || src.gradeExecute < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (src.gradeSign > 150 || src.gradeExecute > 150)
			throw Bureaucrat::GradeTooLowException();
		this->isSigned = src.isSigned;
	}
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low!");
}

const char *Form::DoNotExecuteException::what() const throw()
{
	return ("The form cannot be executed because it is not signed.");
}

std::string Form::getName() const
{
	return this->name;	
}

bool		Form::getIsSigned() const
{
	return this->isSigned;	
}

int			Form::getGradeSign() const
{
	return this->gradeSign;
}

int			Form::getGradeExecute() const
{
	return this->gradeExecute;
}

void		Form::signCheck(Bureaucrat &bureaucrat)
{
	if (this->gradeSign >= bureaucrat.getGrade())
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

void		Form::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::DoNotExecuteException();
	if (this->gradeExecute < executor.getGrade())
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form const &src)
{
	os << "[Bureaucrat Form] => " << "name is "<< src.getName() << ", " << "grade is " << src.getGradeSign() << ", "
	<< "gradeExecute is " << src.getGradeExecute() << ", As aresult, the sign is " << src.getIsSigned() << "(0: False, 1: True).";
	return os;
}