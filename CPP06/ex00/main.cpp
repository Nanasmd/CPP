/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:20:06 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 03:20:09 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "arguments Error: Invalid arguments" << std::endl;
	else
		stringConversion(argv[1]);
	return 0;
}