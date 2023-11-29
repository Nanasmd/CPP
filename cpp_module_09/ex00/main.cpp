/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:41:01 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/29 23:50:21 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    try {
        if (argc != 2) {
            std::cerr << BOLD_RED << "Error: Invalid number of arguments." << RESET << std::endl;
            return EXIT_FAILURE;
        }

        BitcoinDatabase database = getDatabase();
        readInput(database, argv[1]);
    }
    catch (const std::exception& e) {
        std::cerr << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

