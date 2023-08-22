/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:27:07 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:28:01 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(){}

Karen::~Karen(){}

void	Karen::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	void (Karen::*func[4])() = {
					&Karen::debug,
					&Karen::info ,
					&Karen::warning,
					&Karen::error};
	void (Karen::*result)();
	std::string name[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string *findName = std::find(name, name + 4, level);
	int i = findName - name;
	switch (i)
	{
	case 0:
	 	result = func[0];
		(this->*result)();
		std::cout << std::endl;
	case 1:
	 	result = func[1];
		(this->*result)();
		std::cout << std::endl;
	case 2:
	 	result = func[2];
		(this->*result)();
		std::cout << std::endl;
	case 3:
	 	result = func[3];
		(this->*result)();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
