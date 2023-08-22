/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:25:58 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:26:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main()
{
	Karen	karen;
	std::cout << "[KAREN PROGRAM]" << std::endl;
	std::cout << "DEBUG: ";
	karen.complain("DEBUG");
	std::cout << "INFO: ";
	karen.complain("INFO");
	std::cout << "WARNING: ";
	karen.complain("WARNING");
	std::cout << "ERROR: ";
	karen.complain("ERROR");
	return 0;
}