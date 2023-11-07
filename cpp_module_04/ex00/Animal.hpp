/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:36:34 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 13:58:47 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RESET		"\e[0m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define BOLD_RED	"\e[1;31m"
#define BLUE		"\e[0;34m"
#define V_CYAN		"\e[0;38;5;44m"
#define GREEN       "\e[0;32m"
#define YELLOW      "\e[0;33m"

# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		// Constructors
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		
		// Operators
		Animal &operator=(Animal const &src);

		// Getters and Setters
		std::string getType(void) const;
		void setType(std::string const type);
	
		// Member functions
		virtual void makeSound(void) const;
};

#endif
