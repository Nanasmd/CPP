/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:10:19 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:10:20 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		size_t	_grade;

		void _setGrade(int grade);
	
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name);
		Bureaucrat(int grade);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &other);

		std::string const getName() const;
		size_t getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, Bureaucrat *bureaucrat);
