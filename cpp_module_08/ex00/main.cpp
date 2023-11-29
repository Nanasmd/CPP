/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:53 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/09 15:22:36 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

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
#define WITHOUT_NEWLINE	0
#define WITH_NEWLINE	1

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "********************************************" << RESET << std::endl;
	std::cout << PINK << "*              nasamadi's C++ 08           *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << GREEN << "press ENTER to continue" << RESET<< std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void debugMessageConstructors(int newline)
{
	std::cout << std::endl;
	std::cout << BLUE << "constructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageStatus(int newline)
{
	std::cout << std::endl;
	std::cout << PURPLE << "status> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageDestructors(int newline)
{
	std::cout << std::endl;
	std::cout << YELLOW << "destructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageAction(std::string action)
{
	std::cout << std::endl;
	std::cout << GREEN << "action> " << RESET;
	if (action.length())
		std::cout << action << std::endl;
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
	mainHeader();
    int standardSize = 34;
    int messageSize = message.length();
    int spaces = (standardSize - messageSize) / 2;

    std::cout << YELLOW << "************************************" << std::endl << "*" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << message << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << "*" << std::endl << "************************************" << RESET << std::endl << std::endl;
}

int main(void)
{
	{
		titleHeader("TEST WITH VECTOR TYPE");

		std::vector<int> vector;

		for (int i = 0; i < 10; i++)
			vector.push_back(i * i);
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "print the created vector content" << std::endl;
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
		
		try
		{
			debugMessageAction("try to find 25");
			::easyfind(vector, 25);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << e.what() << RESET << std::endl;
		}
		
		try
		{
			debugMessageAction("try to find 100");
			::easyfind(vector, 100);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << "\t" << e.what() << RESET << std::endl;
		}		
	}
	pressEnter();
	{
		titleHeader("TEST WITH DEQUE TYPE");

		std::deque<int> deque;
		
		for (int i = 0; i < 10; i++)
			deque.push_back(i * (i / 2));
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "print the created deque content" << std::endl;
		for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;
		
		try
		{
			debugMessageAction("try to find 0");
			::easyfind(deque, 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << "\t" << e.what() << RESET << std::endl;
		}

		try
		{
			debugMessageAction("try to find 7");
			::easyfind(deque, 7);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << "\t" << e.what() << RESET << std::endl;
		}
	}
	pressEnter();
	{
		titleHeader("TEST WITH LIST TYPE");

		std::list<int> list;
		
		for (int i = 0; i < 10; i++)
			list.push_back(i * (i + 1));
		
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << "print the created list content" << std::endl;
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << "[" << *it << "] ";
		std::cout << std::endl;

		try
		{
			debugMessageAction("try to find 56");
			::easyfind(list, 56);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << "\t" << e.what() << RESET << std::endl;
		}

		try
		{
			debugMessageAction("try to find 91");
			::easyfind(list, 91);
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << "\t" << e.what() << RESET << std::endl;
		}
	}
	pressEnter();
}
