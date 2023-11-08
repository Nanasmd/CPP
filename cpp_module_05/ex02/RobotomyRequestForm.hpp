/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:53 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:10:54 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string const _target;

		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src);
