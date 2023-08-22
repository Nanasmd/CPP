/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:36:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/17 22:36:38 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie *newZombie(std::string);
void randomChump(std::string name);

int main() {
	// watson the zombie
	Zombie *watson = new Zombie("Watson");;
	watson->announce();
	randomChump("otaku zombie");
	delete watson;

	std::cout << std::endl;

	// mickel jackson con tremenda bachata zombie
	Zombie *mickel = newZombie("Mickel");
	mickel->announce();
	// peppa pig
	Zombie *peppa = newZombie("Peppa pig");
	peppa->announce();
	mickel->announce();
	delete mickel;
	peppa->announce();
	delete peppa;

	std::cout << std::endl;

	// random chumps
	randomChump("vegan zombie");

	return 0;
}