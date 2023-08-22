/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:38:44 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 05:48:20 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_04_CPP_MODULE_01_EX01_ZOMBIE_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX01_ZOMBIE_HPP_

#include <iostream>
#include <string>

#include "Random.hpp"

#define NB_ZOMBIE         10

class Zombie {
 private:
  std::string _name;

 public:
  static Zombie *zombieHorde(int N, std::string name);

  void announce(void) const;
  void setName(const std::string& name);
  static std::string randomName(void);

  Zombie(void);
  explicit Zombie(const std::string& name);
  ~Zombie(void);
};

#endif