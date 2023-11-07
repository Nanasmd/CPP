/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:36:46 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 13:58:51 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
# define CAT_HPP

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
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		// Operators
		Cat &operator=(Cat const &src);
		
		// Member functions
		void makeSound(void) const;	
};

#endif
