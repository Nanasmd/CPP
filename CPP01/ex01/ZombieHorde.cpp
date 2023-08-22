/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:39:03 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 05:48:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N, std::string name) {
  Zombie *z = new Zombie[N];

  for (int i = 0 ; i < N ; ++i)
    z[i].setName(name);
  return z;
}