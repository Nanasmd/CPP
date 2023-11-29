/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/17 17:13:47 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define PINK		"\e[0;38;5;199m"
#define WITHOUT_NEWLINE	0
#define WITH_NEWLINE	1

#define MAX_VAL 750

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "********************************************" << RESET << std::endl;
	std::cout << PINK << "*           nasamadi's C++ ARRAY           *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << GREEN << "press ENTER to continue" << RESET << std::endl;
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
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << YELLOW << "************************************" << std::endl << "*" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << message << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << YELLOW << "*" << std::endl << "************************************" << RESET << std::endl;
}

int main(int, char**)
{
	{
		titleHeader("MAIN INTRA TEST");	
		std::cout << std::endl;
			
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
	pressEnter();
	{
		titleHeader("CREATE SIMPLE INT ARRAYS");
		
		debugMessageConstructors(WITH_NEWLINE);
		Array<int> defaultArray;
		Array<int> simple(5);
		Array<int> emptyArray(0);
		
		debugMessageAction("write values on the simple array");
		for (unsigned int i = 0; i < simple.size(); i++)
			simple[i] = rand() % 201 - 100;
			
		debugMessageAction("read values from the simple array");
		for (unsigned int i = 0; i < simple.size(); i++)
			std::cout << "#" << i << ": " << simple[i] << std::endl;
		
		try
		{
			debugMessageAction("try to write on the empty array");
			emptyArray[0] = 42;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}

		try
		{
			debugMessageAction("try to read from a out of range simple array");
			std::cout << simple[5] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}

		debugMessageDestructors(WITH_NEWLINE);		
	}
	pressEnter();
	{
		titleHeader("GET A SIZE OF AN CONST ARRAY");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Array<int> const strictArray(5);
		
		try
		{
			debugMessageAction("try to get the size of the const array");
			std::cout << "\t" << "Size of strictArray: " << strictArray.size() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}

		debugMessageDestructors(WITHOUT_NEWLINE);
	}
	pressEnter();
	{
		titleHeader("CREATE A STRING ARRAY");
		
		debugMessageConstructors(WITH_NEWLINE);
		Array<std::string> defaultArray;
		Array<std::string> stringArray(5);
		Array<std::string> emptyArray(0);
		
		debugMessageAction("write values on the string array");
		stringArray[0] = "This";
		stringArray[1] = "is";
		stringArray[2] = "a";
		stringArray[3] = "string";
		stringArray[4] = "array";

		debugMessageAction("read values from the string array");
		for (unsigned int i = 0; i < stringArray.size(); i++)
			std::cout << "#" << i << ": " << stringArray[i] << std::endl;
		
		try
		{
			debugMessageAction("try to write out of range");
			emptyArray[5] = "plus";
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}

		try
		{
			debugMessageAction("try to read out of range");
			std::cout << emptyArray[5] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << '\n' << RESET;
		}

		debugMessageAction("modify values on the string array");
		stringArray[3] = "modified";

		std::cout << "\t" << "stringArray: ";
		for (unsigned int i = 0; i < stringArray.size(); i++)
			std::cout << stringArray[i] << " ";
		std::cout << std::endl;

		debugMessageDestructors(WITH_NEWLINE);
	}
	pressEnter();
	{
		titleHeader("DEEP COPY TEST");
		
		debugMessageConstructors(WITHOUT_NEWLINE);
		Array<int> original(5);
		
		for (unsigned int i = 0; i < original.size(); i++)
			original[i] = rand() % 201 - 100;
			
		debugMessageAction("read values from the original array");
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << "#" << i << ": " << original[i] << std::endl;
		
		debugMessageConstructors(WITH_NEWLINE);
		Array<int> copy(original);

		debugMessageAction("change value on the original array");
		original[3] = 2147483647;

		debugMessageAction("print values from copy and original array on index[3]");
		std::cout << "\t" << "original: " << original[3] << std::endl;
		std::cout << "\t" << "copy: " << copy[3] << std::endl;

		debugMessageDestructors(WITH_NEWLINE);		
	}
	pressEnter();
}
