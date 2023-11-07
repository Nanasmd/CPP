/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:49:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/16 18:49:14 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << "************************************" << std::endl << "*";
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << message;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << "*" << std::endl << "************************************" << std::endl << std::endl;
}

int	main(void)
{
	titleHeader("DIAMOND DEFAULT");
	DiamondTrap	firstMonster;

	firstMonster.whoAmI();
	firstMonster.attack("citizens");
	std::cout << firstMonster << std::endl;
	firstMonster.takeDamage(90);
	std::cout << firstMonster << std::endl;
	firstMonster.beRepaired(10);
	std::cout << firstMonster << std::endl;
	firstMonster.guardGate();
	firstMonster.highFivesGuys();
	firstMonster.takeDamage(40);
	std::cout << firstMonster << std::endl;
	firstMonster.attack("citizens");
	pressEnter();

	titleHeader("DIAMOND SPECIFIC");
	DiamondTrap	secondMonster("Troll");
	
	secondMonster.whoAmI();
	secondMonster.attack("citizens");
	std::cout << secondMonster << std::endl;
	secondMonster.takeDamage(18);
	std::cout << secondMonster << std::endl;
	secondMonster.beRepaired(153);
	std::cout << secondMonster << std::endl;
	secondMonster.guardGate();
	secondMonster.highFivesGuys();
	secondMonster.takeDamage(240);
	std::cout << secondMonster << std::endl;
	secondMonster.attack("citizens");
	pressEnter();

	titleHeader("DIAMOND COPY");
	DiamondTrap	thirdMonster(secondMonster);
	thirdMonster.attack("citizens");
	std::cout << thirdMonster << std::endl;
	pressEnter();

	titleHeader("DIAMOND DESTUCTORS");
}
