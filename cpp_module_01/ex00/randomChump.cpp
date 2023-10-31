/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:55:45 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/16 15:44:08 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Crée un nouveau zombie sur la stack, l'annonce, puis le détruit
// making use of RAII principles, since the Zombie's
// destructor will be automatically called when the function ends.
// create a zombie on the stack 
// and let it announce itself is an excellent example of RAII.

void	randomChump(const std::string& name) 
{
	Zombie chump(name);
	chump.announce();
}
