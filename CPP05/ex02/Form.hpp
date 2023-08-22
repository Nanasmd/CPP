/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:11:45 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:11:47 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Form;
#include "Bureaucrat.hpp"

class Form{
private:
	const std::string name;
	const int	gradeSign;
	const int	gradeExecute;
	bool	isSigned;

public:
	Form();
	virtual ~Form();

	Form(std::string name, int gradeSign, int gradeExecute);
	Form(Form const &src);
	Form &operator=(Form const &src);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeSign() const;
	int			getGradeExecute() const;
	void		signCheck(Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException: public std::exception{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException: public std::exception{
		public:
			const char* what() const throw();
	};

	class DoNotExecuteException: public std::exception{
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Form const &src);

#endif