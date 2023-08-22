/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:45:37 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/17 22:45:46 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout
			<< "Error: Invalid number of arguments." << '\n'
			<< "Usage: <program> <file name> <search> <replace>" << std::endl;
		return 1;
	}
	if (Sed::replace(argv[1], argv[2], argv[3])) {
		return 1;
	}
	return 0;
}
