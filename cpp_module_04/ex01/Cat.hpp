/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:20:11 by nasamadi          #+#    #+#             */
/*   Updated: 2023/11/02 14:20:12 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
		
	public:
		// Constructors
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		// Operators
		Cat &operator=(Cat const &src);
		
		// Member functions
		void makeSound(void) const;

		// Getters
		Brain *getBrain(void) const;
};

#endif
