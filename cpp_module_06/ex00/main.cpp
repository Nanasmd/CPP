/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:37:58 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/08 13:25:07 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	mainHeader() 
{
	std::cout << "\033c";
	std::cout << PINK << "********************************************" << RESET << std::endl;
	std::cout << PINK << "*          nasamadi's C++ CONVERTER        *" << RESET << std::endl;
	std::cout << PINK << "********************************************" << RESET << std::endl << std::endl;
}

int	main(int ac, char **av)
{
	mainHeader();
	if (ac != 2)
	{
		std::cout << YELLOW << "Usage: ./convert [input]" << RESET << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}
