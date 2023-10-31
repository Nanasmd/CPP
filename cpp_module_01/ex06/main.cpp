/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:10:20 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/17 18:16:29 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	mainHeader()
{
	std::cout << "\033c";
	std::cout << LILAC << "***********************************************" << RESET << std::endl;
	std::cout << LILAC << "*            nasamadi's harlFilter            *" << RESET << std::endl;
	std::cout << LILAC << "***********************************************" << RESET << std::endl << std::endl;
	//std::cout << "We will pass by the program various levels" << std::endl;
}

int	main(int ac, char **av)
{
	Harl harl;
	
	mainHeader();
	
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	level = -1;

	if (ac != 2)
	{
		std::cout << YELLOW << "Usage: ./harlFilter [LEVEL]" << RESET << std::endl;
		return (1);
	}

	for (int i = 0; i < 4; i++)
		if (levels[i] == av[1])
			level = i;
	while (level < 4)
	{
		switch (level)
		{
			default:
				std::cout << BOLD_RED << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
				break;
			case 0:
				std::cout << GREEN << "[ DEBUG ]" << RESET << std::endl;
				harl.complain("DEBUG");
				break;
			case 1:
				std::cout << GREEN << "[ INFO ]" << RESET << std::endl;
				harl.complain("INFO");
				break;
			case 2:
				std::cout << GREEN << "[ WARNING ]" << RESET << std::endl;
				harl.complain("WARNING");
				break;
			case 3:
				std::cout << GREEN << "[ ERROR ]" << RESET << std::endl;
				harl.complain("ERROR");
				break;
		}
		if (level == 3 || level == -1)
			break;
		else
		{
			level++;
			std::cout << std::endl;	
		}
	}
}
