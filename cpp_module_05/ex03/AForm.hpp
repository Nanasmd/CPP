/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:11:29 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/01 11:11:30 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool		_isSigned;
		int const	_signGrade;
		int const	_executeGrade;

		void _checkGrades(int signGrade, int executeGrade);
	
	public:
		AForm();
		AForm(AForm const &other);
		AForm(int signGrade, int executeGrade);
		AForm(std::string const &name);
		AForm(std::string const &name, int signGrade, int executeGrade);
		virtual ~AForm();

		AForm &operator=(AForm const &other);

		std::string const getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &bureaucrat) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm *src);
