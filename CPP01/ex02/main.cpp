/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:40:24 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/17 22:40:31 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	// initialise vars
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	// print address of the string
	std::cout << "\nADDRESS OF THE STRING:\n\n"
		<< "string:    " << &string << '\n'
		<< "stringPTR: " << stringPTR << '\n'
		<< "stringREF: " << &stringREF << '\n';

	// display string content
	std::cout << "\nCONTENT OF THE STRING:\n\n"
		<< "string:    " << string << '\n'
		<< "stringPTR: " << *stringPTR << '\n'
		<< "stringREF: " << stringREF << '\n'
		<< std::endl;

	return 0;
}