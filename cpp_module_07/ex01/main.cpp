/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:26 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/14 13:33:46 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define BOLD_RED	"\e[1;31m"
#define V_CYAN		"\e[0;38;5;44m"

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "********************************************" << RESET << std::endl;
	std::cout << PINK << "*            nasamadi's C++ ITER           *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << GREEN << "press ENTER to continue" << RESET << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
	mainHeader();
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << YELLOW << "************************************" << std::endl << "*" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << message << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << "*" << std::endl << "************************************" << std::endl << std::endl << RESET;
}

int main(void)
{
	{
		titleHeader("INT ARRAY TEST");

		int array[] = {1, 22, 333, 4444, 55555, 666666, 7777777, 88888888, 999999999, 1010101010};

		::iter(array, 10, printContent<int>);
	}
	pressEnter();
	{
		titleHeader("STRING ARRAY TEST");

		std::string array[] = {
			"first", "second", "third", "fourth",
			"fifth", "sixth", "seventh", "eighth",
			"ninth", "tenth"};
		
		::iter(array, 10, printContent<std::string>);
	}
	pressEnter();
}
