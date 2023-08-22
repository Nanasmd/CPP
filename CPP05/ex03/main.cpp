/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:18:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:18:13 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	Intern_test(std::string const &name, std::string const &target)
{
	Intern  someRandomIntern;
	Form* rrf;
	Bureaucrat internB("bure", 42);

	rrf = someRandomIntern.makeForm(name, target);
	if (rrf)
	{
		try
		{
			std::cout << internB;
			internB.signForm(*rrf);
			std::cout << *rrf << std::endl;
			internB.executeForm(*rrf);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete rrf;
	}
	std::cout << std::endl;
}

int		main()
{
	Intern_test("robotomy request", "Bender");
	Intern_test("Shrubbery Creation", "Dender");
	Intern_test("Presidential Pardon", "Cender");
	Intern_test("UnknownForm", "Aender");
}