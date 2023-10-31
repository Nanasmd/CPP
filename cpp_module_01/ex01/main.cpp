/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:05:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/17 19:58:47 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << LILAC << "*****************************************" << RESET << std::endl;
	std::cout << LILAC << "*         nasamadi's C++ ZOMBIES        *" << RESET << std::endl;
	std::cout << LILAC << "*****************************************" << RESET << std::endl << std::endl;
}

// Fonction principale pour tester la classe et la fonction zombieHorde
int	main(void)
{
	std::string zombiesClass;
	int			hordeSize;
	const int   MAX_HORDE_SIZE = 1000000;
	Zombie 		*zombie;

	mainHeader();
	while (1)
	{
		std::cout << YELLOW << "Enter the size of the zombie's horde: " << RESET << std::endl;

		std::cin >> hordeSize;
		
		if (!std::cin || std::cin.eof()) 
		{
			std::cout << BOLD_RED << "Exiting due to user request or input error." << RESET << std::endl;
			return 1; // Exit the program
		}
		else if (std::cin.fail() || hordeSize <= 0 || hordeSize > MAX_HORDE_SIZE)
		{
			std::cout << BOLD_RED << "Invalid input. Try again with a positive integer." << RESET << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else
			break ;
	}
	std::cout << YELLOW << "Now enter a name for your zombies class: " << RESET << std::endl;
	std::cin >> zombiesClass;
	
	mainHeader();
	zombie = zombieHorde(hordeSize, zombiesClass);
	for (int i = 0; i < hordeSize; i++)
		zombie[i].announce();
	delete [] zombie;
}

// Notions :

// Dynamic Memory Allocation:
// In C++98, dynamic memory allocation is handled using the new (for allocation) and delete (for deallocation) operators.
// Objects and arrays created with new are stored in the heap (dynamic memory), and it's crucial to release this memory using delete (or delete[] for arrays) to prevent memory leaks.

// Pointers:
// Pointers are a fundamental concept in C++98. They store the memory address of another variable.
// In this exercise, pointers to objects (instances of the Zombie class) play a vital role, especially when creating a horde of zombies in the heap.

// Error management :

// The error you're encountering is due to an overflow. 
// The value 2147483647 is the maximum value for a signed 32-bit integer (often the size of int in many systems).
// When you try to allocate memory for this many zombies, it will attempt to allocate 2147483647 × sizeof(Zombie) bytes
// This allocation will likely be far larger than the available memory on your system, leading to a bad allocation or other related error.