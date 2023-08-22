/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:27:35 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:27:43 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int		main(int argc, char **argv)
{
	Karen	karen;

	if (argc != 2) {
		std::cout << "argument error." << std::endl;
		return 0;
	}
	std::string level = argv[1];
	karen.complain(level);
	return 0;
}