/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:11:21 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:11:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>

#define HIGH_GRADE 1
#define LOW_GRADE 150

class Bureaucrat;
# include "Form.hpp"

class Bureaucrat{
private:
	std::string name;
	int		grade;
public:
	Bureaucrat();
	virtual ~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &src);
	void	gradeIncrease();
	void	gradeDecrease();
	void	signForm(Form &form);
	void	executeForm(Form const &form);
	class GradeTooHighException: public std::exception{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException: public std::exception{
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &src);

#endif