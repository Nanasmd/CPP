/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:12:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:12:11 by nasamadi         ###   ########.fr       */
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

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if ((int)bureaucrat.getGrade() > this->getExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else 
	{
		std::cout << "\t" << "zZzzzzzZZZZZzzZzZZzzZzZzz..." << std::endl;
		if (RobotomyTry++ % 2)
			std::cout << "\t" << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
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
