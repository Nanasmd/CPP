/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:12:02 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:12:03 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "create PresidentialPardonForm " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm("PresidentialPardonForm", 25, 5), _target(other.getTarget())
{
	std::cout << "create PresidentialPardonForm copy of " << other.getName() << std::endl;
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "destroy PresidentialPardonForm " << this->_target << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	std::cout << "start assignation PresidentialPardonForm to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const{return (this->_target);}

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

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src)
{
	std::string isSigned = src->getIsSigned() ? " is signed" : " isn't signed";
	out << src->getName() << isSigned;
	out << ". Sign-grade: " << src->getSignGrade();
	out << ", execution-grade " << src->getExecuteGrade() << std::endl;
	return (out);
}
