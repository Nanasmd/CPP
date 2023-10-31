/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:56:11 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/17 20:03:30 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

#define RESET		"\e[0m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define BOLD_RED	"\e[1;31m"
#define BLUE		"\e[0;34m"
#define V_CYAN		"\e[0;38;5;44m"
#define GREEN       "\e[0;32m"
#define YELLOW      "\e[0;33m"

class Zombie
{
	public:
		Zombie();
		Zombie(const std::string& name);
		~Zombie();
		
		void announce() const;
		
	private:
		std::string _name;
};

Zombie	*newZombie(const std::string& name);
void	randomChump(const std::string& name);

#endif

// Heap & Stack in c++

// Used const qualifiers where appropriate, especially for methods that don't modify member data.
// Used const std::string& as function parameters to avoid unnecessary string copies.
