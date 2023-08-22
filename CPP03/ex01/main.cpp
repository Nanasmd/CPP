/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:42:22 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:42:24 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main(void)
{
	ClapTrap	sorceress("sorceress");
	ScavTrap	martial_artist("martial artist");

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
	return (0);
}