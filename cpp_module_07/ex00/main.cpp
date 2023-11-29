/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:39:10 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/23 16:41:19 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

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
	std::cout << PINK << "*              nasamadi's C++ 07           *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

void	pressEnter(void)
{
	std::cout << std::endl << GREEN << "press ENTER to continue" << RESET<< std::endl;
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
	std::cout << YELLOW << "*" << std::endl << "************************************" << RESET << std::endl << std::endl;
}

int main(void)
{
	{
		titleHeader("SUBJECT TEST");
		
		int a = 2;
		int b = 3;
		
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		
		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	pressEnter();
	{
		titleHeader("SAME TYPE TEST");

		std::string first = "first";
		std::string second = "second";

		std::cout << V_CYAN << "===== before swap =====" << RESET << std::endl;
		std::cout << "first = " << first << std::endl;
		std::cout << "second = " << second << std::endl;
		std::cout << std::endl;

		::swap(first, second);

		std::cout << BLUE << "===== after swap =====" << RESET << std::endl;
		std::cout << "first = " << first << std::endl;
		std::cout << "second = " << second << std::endl;
		std::cout << std::endl;

		float a = -987.6895659f;
		float b = -987.6545654f;

		std::cout << "float a = " << a << std::endl;
		std::cout << "float b = " << b << std::endl;
		std::cout << std::endl;
		
		std::cout << "who is min between a and b? ";
		std::cout << ::min(a, b) << std::endl;

		std::cout << "who is max between a and b? ";
		std::cout << ::max(a, b) << std::endl;
	}
	pressEnter();
	// {
	// 	titleHeader("DIFFERENT TYPE TEST");

	// 	std::string first = "first";
	// 	char second = 's';

	// 	std::cout << "===== before swap =====" << std::endl;
	// 	std::cout << "first = " << first << std::endl;
	// 	std::cout << "second = " << second << std::endl;
	// 	std::cout << std::endl;

	// 	::swap(first, second);
	// 	std::cout << "===== after swap =====" << std::endl;
	// 	std::cout << "first = " << first << std::endl;
	// 	std::cout << "second = " << second << std::endl;
	// 	std::cout << std::endl;

	// 	int a = 123;
	// 	float b = 123.456f;

	// 	std::cout << "int a = " << a << std::endl;
	// 	std::cout << "float b = " << b << std::endl;
	// 	std::cout << std::endl;

	// 	std::cout << "who is min between a and b? ";
	// 	std::cout << ::min(a, b) << std::endl;

	// 	std::cout << "who is max between a and b? ";
	// 	std::cout << ::max(a, b) << std::endl;
	// }
}
