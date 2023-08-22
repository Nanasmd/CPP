/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:49:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:49:43 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int		main(void)
{
	DiamondTrap Summoner("summoner");

	Summoner.whoAmI();
	Summoner.attack("valtan");
	Summoner.takeDamage(10);
	Summoner.showState();
	Summoner.useSkill("valtan");
	Summoner.showState();
	Summoner.beRepaired(30);
	Summoner.showState();
	Summoner.guardGate();
	Summoner.highFivesGuys();
	return (0);
}