/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPadonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:12:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:12:15 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	Form("PresidentialPardonForm", 25, 5), target("Unknown")
{
	std::cout << "PresidentialPardonForm Constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "PresidentialPardonForm equal operator called." << std::endl;
	if(this != &src)
		this->target = src.target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target):
	Form("PresidentialPardonForm", 25, 5), target(_target)
{
	std::cout << "PresidentialPardonForm Constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):
	Form("PresidentialPardonForm", 25, 5), target(src.target)
{
	std::cout << "PresidentialPardonForm copy Constructor called." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Deeblebrox." << std::endl;
}