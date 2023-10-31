/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:55:40 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/16 15:44:28 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Crée un nouveau zombie sur la heap en allouant 
// de la memoire dynamiquement et renvoie un pointeur vers lui

Zombie	*newZombie(const std::string& name) 
{
	return (new Zombie(name));
}
