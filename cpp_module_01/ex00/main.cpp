/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:55:26 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/17 20:19:36 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <algorithm> // for std::remove

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << LILAC << "*****************************************" << RESET << std::endl;
	std::cout << LILAC << "*         nasamadi's C++ ZOMBIES        *" << RESET << std::endl;
	std::cout << LILAC << "*****************************************" << RESET << std::endl << std::endl;
}

int main() 
{
    std::string chumpName;
    std::string zombieName;
    Zombie *zombie;

    mainHeader();

    // Input for chumpName
    while (true) 
    {
        std::cout << YELLOW << "Enter a name for the chump: " << RESET << std::endl;
        std::getline(std::cin, chumpName);

        if (!std::cin || std::cin.eof()) 
        {
            std::cout << BOLD_RED << "Exiting due to user request or input error." << RESET << std::endl;
            return 1; 
        }
        if (chumpName.empty()) 
        {
            std::cout << BOLD_RED << "Please input a valid name for the chump." << RESET << std::endl;
            continue ;
        }
        break ;
    }

    // Input for zombieName
    while (true) 
    {
        std::cout << YELLOW << "Now enter a name for the zombie: " << RESET << std::endl;
        std::getline(std::cin, zombieName);

        if (!std::cin || std::cin.eof()) 
        {
            std::cout << BOLD_RED << "Exiting due to user request or input error." << RESET << std::endl;
            return 1; // Exit the program
        }
        if (zombieName.empty()) 
        {
            std::cout << BOLD_RED << "Please input a valid name for the zombie." << RESET << std::endl;
            continue ;
        }
        break ;
    }

    mainHeader();

    zombie = newZombie(zombieName); 
    zombie->announce();

    randomChump(chumpName);

    delete zombie;

    return 0;
}

