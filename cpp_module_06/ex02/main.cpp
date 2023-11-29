/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:38:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 13:33:26 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "********************************************" << RESET << std::endl;
	std::cout << PINK << "*              nasamadi's C++ 06           *" << RESET << std::endl;
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
    int standardSize = 34;
    int messageSize = message.length();
    int spaces = (standardSize - messageSize) / 2;

    std::cout << LILAC << "************************************" << std::endl << "*" << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << LILAC << message << RESET;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << LILAC << "*" << std::endl << "************************************" << RESET << std::endl;
}

Base * generate(void)
{
	switch(std::rand() % 3)
	{
		case 0:
			std::cout << "create new A instance" << std::endl;
			return (new A());
		case 1:
			std::cout << "create new B instance" << std::endl;
			return (new B());
		case 2:
			std::cout << "create new C instance" << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cout << "unknown" << std::endl;
	}
}

int	main()
{
	{
		titleHeader("INDENTIFY FROM POINTER");
		Base *base;

		for (int i = 0; i < 5; i++)
		{
			base = generate();
			
			std::cout << "Base address: " << base << std::endl;
			std::cout << "Base type   : ";
			
			identify(base);
			
			std::cout << std::endl;
			delete base;
		}
	}
	pressEnter();
	{
		titleHeader("INDENTIFY FROM REFERENCE");
		Base *base;
		
		for (int i = 0; i < 5; i++)
		{
			base = generate();
			
			std::cout << "Base address: " << base << std::endl;
			std::cout << "Base type   : ";
			
			identify(*base);
			
			std::cout << std::endl;
			delete base;
		}
	}
	pressEnter();
	{
		titleHeader("UNKNOWN TYPE");

		Base *emptyPointer = NULL;
		Base emptyClass;

		std::cout << "emptyPointer address: " << emptyPointer << std::endl;
		std::cout << "Base type           : ";
		identify(emptyPointer);

		std::cout << std::endl;
		std::cout << "emptyClass address  : " << &emptyClass << std::endl;
		std::cout << "Base type           : ";
		identify(emptyClass);		
	}
	pressEnter();
}
