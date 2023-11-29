/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:24 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/14 14:05:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
		titleHeader("SUBJECT TEST");
		std::cout << std::endl;
		
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	pressEnter();
	{
		titleHeader("SMALL TEST");

		Span sp = Span(15);
		
		debugMessageAction("auto fill the storage");
		sp.autoFill();

		debugMessageStatus(WITH_NEWLINE);
		std::cout << sp;
		
		debugMessageAction("Print the shortest span");
		std::cout << "\t" << sp.shortestSpan() << std::endl;

		debugMessageAction("Print the longest span");
		std::cout << "\t" << sp.longestSpan() << std::endl;
		
	}
	pressEnter();
	{
		titleHeader("EMPTY TEST");
		
		Span sp;

		debugMessageStatus(WITH_NEWLINE);
		std::cout << sp;
	}
	pressEnter();
	{
		titleHeader("ERROR TEST");

		Span small = Span(1);

		small.addNumber(1);
		try
		{
			debugMessageAction("try to print the shortest span with one number");
			std::cout << "\t" << small.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << e.what() << RESET << std::endl;
		}

		try
		{
			debugMessageAction("try to print the longest span with one number");
			std::cout << "\t" << small.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << BOLD_RED << e.what() << RESET << std::endl;
		}

		try
		{
			debugMessageAction("try to add number in full storage");
			small.addNumber(2);
		}
		catch(const std::exception& e)
		{
			std::cerr << "\t" << BOLD_RED << e.what() << RESET << std::endl;
		}
		
	}
	pressEnter();
	{
		titleHeader("ONE HUNDRED THOUSAND TEST");

		Span sp = Span(100000);
		
		debugMessageAction("auto fill the storage with 100000 numbers");
		sp.autoFill();
		
		pressEnter();
		
		debugMessageStatus(WITH_NEWLINE);
		std::cout << sp;
		
		try
		{
			debugMessageAction("try to print the shortest span");
			std::cout << "\t" << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\t" << BOLD_RED << e.what() << RESET << std::endl;
		}

		try
		{
			debugMessageAction("try to print the longest span");
			std::cout << "\t" << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\t" << BOLD_RED << e.what() << RESET << std::endl;
		}
	}
	pressEnter();
}
