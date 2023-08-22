/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:38:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:38:52 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main(void)
{
	ClapTrap  lostark("sorceress");

	lostark.attack("Baltan");
	lostark.takeDamage(5);
	lostark.useSkill("Baltan");
	lostark.showState();
	lostark.beRepaired(5);
	lostark.showState();
	lostark.takeDamage(10);
	lostark.takeDamage(10);
	lostark.attack("Baltan");
	return (0);
}