/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 05:48:58 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 05:49:04 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCLE_04_CPP_MODULE_01_EX01_RANDOM_HPP_
#define CIRCLE_04_CPP_MODULE_01_EX01_RANDOM_HPP_

class Random {
 private:
  static int seed;

  Random(void);
  ~Random(void);

 public:
  static double randv(void);
  static double randr(double min, double max);
};

#endif