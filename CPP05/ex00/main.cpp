/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:08:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:08:16 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	in_de_creaseTest()
{
	std::cout << "Bureaucrat increase, decrease test" << std::endl;
	Bureaucrat initBureaucrat = Bureaucrat();
	std::cout << initBureaucrat << std::endl;
	initBureaucrat.gradeIncrease();
	initBureaucrat.gradeIncrease();
	initBureaucrat.gradeDecrease();
	std::cout << initBureaucrat << std::endl;
}

void	exceptionTest()
{
	std::cout << "Bureaucrat exception test" << std::endl;
	std::cout << "Bureaucrat TooHigh test" << std::endl;
	try 
	{
		Bureaucrat bureaucrat1("lanarang", 0);
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat TooLow test" << std::endl;
	try 
	{
		Bureaucrat bureaucrat2("whanarang", 151);
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat increase TooHigh test" << std::endl;
	try 
	{
		Bureaucrat bureaucrat3("lanarang", 1);
		bureaucrat3.gradeIncrease();
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat decrease TooLow test" << std::endl;
	try 
	{
		Bureaucrat bureaucrat4("whanarang", 150);
		bureaucrat4.gradeDecrease();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	generalTest()
{
	Bureaucrat bureaucrat("newnarang", 30);
	Bureaucrat copyBureaucrat = Bureaucrat(bureaucrat);
	std::cout << copyBureaucrat << std::endl;
}

int		main()
{
	in_de_creaseTest();
	std::cout << std::endl;
	exceptionTest();
	std::cout << std::endl;
	generalTest();
}