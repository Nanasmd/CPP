/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:16:00 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:16:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
	typedef Form* (*reqFunc)(std::string const&);
	struct internForm {
		std::string name;
		reqFunc		req;
	};
	internForm formList[3];

public:
	Intern();
	virtual ~Intern();
	Intern(Intern const &src);
	Intern &operator=(Intern const &src);
	Form *makeForm(std::string reqName, std::string target);
};

Form *createSCF(std::string const &target);
Form *createRRF(std::string const &target);
Form *createPPF(std::string const &target);

#endif