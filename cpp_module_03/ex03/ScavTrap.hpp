/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:49:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/25 20:02:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#define RESET		"\e[0m"
#define BOLD 		"\033[1m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define BOLD_RED	"\e[1;31m"
#define BLUE		"\e[0;34m"
#define V_CYAN		"\e[0;38;5;44m"
#define GREEN       "\e[0;32m"
#define YELLOW      "\e[0;33m"

#include "ClapTrap.hpp"
#include <iostream>

class	ScavTrap : virtual public ClapTrap
{
	protected:
		static int const initHit = 100;
		static int const initEnergy = 50;
		static int const initDamage = 20;
		
	public:
		// Constructors 
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &copy);
		~ScavTrap(void);

		// Operators
		ScavTrap	&operator=(ScavTrap const &copy);

		// Special member functions
		void	guardGate(void);
		void	attack(std::string const &target);
};

#endif