/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:39:39 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 05:47:45 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
  std::cout << "Creating a Horde of " << NB_ZOMBIE << " Zombies"
    << std::endl << std::endl;
  Zombie *z = Zombie::zombieHorde(NB_ZOMBIE, Zombie::randomName());
  std::cout << std::endl << "Burying a Horde of " << NB_ZOMBIE << " Zombies"
    << std::endl << std::endl;
  delete[] z;
  return 0;
}