/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:12:22 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:12:23 by nasamadi         ###   ########.fr       */
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

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const _target;

		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *src);
