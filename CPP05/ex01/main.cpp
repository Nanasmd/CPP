/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:10:22 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:10:26 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void FormTest()
{
	Bureaucrat	corps1("Valtan", 60);
	Bureaucrat	corps2("Biackiss", 40);
	Form		petrania("Invasion of Acracia", 50, 50);
	std::cout << corps1 << std::endl;
	std::cout << corps2 << std::endl;
	std::cout << petrania << std::endl;
	try
	{
		corps1.signForm(petrania);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << petrania << std::endl;

	try
	{
		corps2.signForm(petrania);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << petrania << std::endl;
}

void FormOtherTest()
{
	Bureaucrat initBureaucrat = Bureaucrat();
	Form initForm = Form();
	std::cout << initBureaucrat << std::endl;
	std::cout << initForm << std::endl;
	try
	{
		initBureaucrat.signForm(initForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << initForm << std::endl;

	Form	newForm("Form test.", 148, 148);
	std::cout << newForm << std::endl;
	initBureaucrat.gradeIncrease();
	std::cout << initBureaucrat << std::endl;
	try
	{
		initBureaucrat.signForm(newForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	initBureaucrat.gradeIncrease();
	std::cout << initBureaucrat << std::endl;
	try
	{
		initBureaucrat.signForm(newForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


int		main()
{
	FormTest();
	std::cout << std::endl;
	FormOtherTest();
}