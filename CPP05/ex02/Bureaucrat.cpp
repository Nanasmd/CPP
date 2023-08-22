/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:11:08 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:11:11 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Jhon doe"), grade(LOW_GRADE)
{
	std::cout << "Unidentified Bureaucrat Constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name), grade(_grade)
{
	std::cout << "Bureaucrat Constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): name(src.name), grade(src.grade)
{
	std::cout << "Bureaucrat copy Constructor called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Bureaucrat equal operator called." << std::endl;
	if (this != &src)
	{
		if (src.grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (src.grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade = src.grade;
	}
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low!");
}

void Bureaucrat::gradeIncrease()
{
	if (this->grade == HIGH_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void Bureaucrat::gradeDecrease()
{
	if (this->grade == LOW_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

std::string Bureaucrat::getName() const
{
	return this->name;	
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.signCheck(*this);
		std::cout << this->getName() << " signs " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " cannot signs " << form << " because ";
		std::cerr << e.what() << '\n';
	}
	
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " cannot executes " << form << " because ";
		std::cerr << e.what() << '\n';
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &src)
{
	os <<  "name is "<< src.getName() << ", " << "grade is " << src.getGrade() << ".";
	return os;
}