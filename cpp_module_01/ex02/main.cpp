/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:09:57 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/17 20:44:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define RESET		"\e[0m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define BOLD_RED	"\e[1;31m"
#define BLUE		"\e[0;34m"
#define V_CYAN		"\e[0;38;5;44m"
#define GREEN       "\e[0;32m"
#define YELLOW      "\e[0;33m"

int	main()
{
	std::string text = "HI THIS IS BRAIN";
	std::string *stringPTR = &text;
	std::string &stringREF = text;

	std::cout << GREEN << "Address of text     : " << RESET << &text  << std::endl;
	std::cout << GREEN << "Address of stringPTR: " << RESET << stringPTR << std::endl;
	std::cout << GREEN << "Address of stringREF: " << RESET << &stringREF << std::endl << std::endl;

	std::cout << BLUE << "text content     : " << RESET << text << std::endl;
	std::cout << BLUE  << "StringPTR content: " << RESET << *stringPTR << std::endl;
	std::cout << BLUE  << "StringREF content: " << RESET << stringREF << std::endl;

	std::cout << std::endl << PINK << "That is, everyone points to the same address." << RESET << std::endl;
}
