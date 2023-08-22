/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:45:31 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:45:33 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	ClapTrap	sorceress("sorceress");
	ScavTrap	martial_artist("martial artist");
	FragTrap	fighter("fighter");

	sorceress.showState();
	martial_artist.showState();

	sorceress.useSkill("martial artist");
	martial_artist.takeDamage(20);
	sorceress.beRepaired(20);

	martial_artist.attack("sorceress");
	sorceress.takeDamage(20);

	sorceress.showState();
	martial_artist.showState();

	sorceress.beRepaired(5);
	martial_artist.beRepaired(5);

	sorceress.showState();
	martial_artist.showState();

	martial_artist.guardGate();

	fighter.showState();
	fighter.attack("argus");
	fighter.takeDamage(90);
	fighter.beRepaired(10);
	fighter.showState();
	fighter.highFivesGuys();
	return (0);
}