/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:10:20 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/17 18:07:22 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	pressEnter()
{
	std::cout << GREEN << std::endl << "press ENTER to continue" << RESET << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void	mainHeader()
{
	std::cout << "\033c";
	std::cout << LILAC << "*********************************************" << RESET << std::endl;
	std::cout << LILAC << "*            nasamadi's HARL 2.0            *" << RESET << std::endl;
	std::cout << LILAC << "*********************************************" << RESET << std::endl << std::endl;
	std::cout << "We will pass by the program various levels" << std::endl;
}

int	main()
{
	Harl harl;

	mainHeader();
	pressEnter();
	
	std::cout << PINK << "[ DEBUG ]" << RESET << std::endl << std::endl;
	harl.complain("DEBUG");
	pressEnter();

	std::cout << PINK << "[ INFO ]" << RESET << std::endl << std::endl;
	harl.complain("INFO");
	pressEnter();

	std::cout << PINK << "[ WARNING ]" << RESET << std::endl << std::endl;
	harl.complain("WARNING");
	pressEnter();

	std::cout << PINK << "[ ERROR ]" << RESET << std::endl << std::endl;
	harl.complain("ERROR");
	pressEnter();
}