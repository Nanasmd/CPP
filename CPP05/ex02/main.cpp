/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:14:04 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:14:07 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	ShrubberyCreationFormTest1()
{
	try
	{	
		Bureaucrat bureaucrat("chanykim", 42);
		ShrubberyCreationForm  shrubbery("openproject");
		bureaucrat.signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		//shrubbery.execute(bureaucrat);
		bureaucrat.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ShrubberyCreationFormTest2()
{
	try
	{	
		Bureaucrat bureaucrat("nice", 150);
		ShrubberyCreationForm  shrubbery("happy");
		bureaucrat.signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		//shrubbery.execute(bureaucrat);
		bureaucrat.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	RobotomyRequestFormTest1()
{
	try
	{	
		Bureaucrat bureaucrat("robotics", 42);
		RobotomyRequestForm  robotomy("Notes");
		bureaucrat.signForm(robotomy);
		std::cout << robotomy << std::endl;
		bureaucrat.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	RobotomyRequestFormTest2()
{
	try
	{
		Bureaucrat bureaucrat("roborobo", 50);
		RobotomyRequestForm  robotomy("tics Notes");
		bureaucrat.signForm(robotomy);
		std::cout << robotomy << std::endl;
		bureaucrat.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	PresidentialPardonFormTest1()
{
	try
	{
		Bureaucrat bureaucrat("presi", 2);
		PresidentialPardonForm  president("pardon");
		bureaucrat.signForm(president);
		std::cout << president << std::endl;
		bureaucrat.executeForm(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	PresidentialPardonFormTest2()
{
	try
	{
		Bureaucrat bureaucrat("presisisisi", 10);
		PresidentialPardonForm  president("pardon huh!");
		bureaucrat.signForm(president);
		std::cout << president << std::endl;
		bureaucrat.executeForm(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int		main()
{
	ShrubberyCreationFormTest1();
	ShrubberyCreationFormTest2();
	std::cout << std::endl;
	RobotomyRequestFormTest1();
	RobotomyRequestFormTest2();
	std::cout << std::endl;
	PresidentialPardonFormTest1();
	PresidentialPardonFormTest2();
}